#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int x = []() { // reduce runtime from 356ms to 289ms, limitation is 400ms
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    return 0;
}();

class Solution
{
private:
    unordered_map<string, pair<string, bool>> rec; // first name, father name, isMale

public:
    Solution()
    {
        int n;
        cin >> n;
        while (n--) {
            string first, father;
            cin >> first >> father;
            char lastChr = father.back();
            bool isNotViking = (lastChr == 'm' || lastChr == 'f'), isMale = (lastChr == 'm' || lastChr == 'n');
            string fname = (isNotViking ? "" : father.substr(0, father.size() - (isMale ? 4 : 7)));
            rec[first] = make_pair(fname, isMale);
        }
    }

    void check()
    {
        int m;
        cin >> m;
        while (m--) {
            string n1, n2, n3, n4;
            cin >> n1 >> n2 >> n3 >> n4;
            if (rec.find(n1) == rec.end() || rec.find(n3) == rec.end()) {
                cout << "NA\n";
            } else if (rec[n1].second == rec[n3].second) {
                cout << "Whatever\n";
            } else {
                unordered_set<string> tmp1, tmp2, tmp3, tmp4;
                if (fillSet(tmp1, n1, 4)) fillSet(tmp2, n1);
                if (fillSet(tmp3, n3, 4)) fillSet(tmp4, n3);
                bool flag = (noIntersect(tmp1, tmp3) && noIntersect(tmp1, tmp4) && noIntersect(tmp3, tmp2));
                cout << (flag ? "Yes" : "No") << '\n';
            }
        }
    }

private:
    bool fillSet(unordered_set<string> &s, string &name, int limit = 0x3F3F3F3F)
    {
        for (int i = 0; i < limit; ++i) {
            if (name.empty()) break; // not viking, or emplaced a new pair and got an empty string
            s.insert(name);
            name = rec[name].first;
        }
        return true;
    }

    bool noIntersect(const unordered_set<string> &s1, const unordered_set<string> &s2)
    {
        if (s2.size() > 4) { // T(n)=O(mlogn), let `n` be the larger one
            for (auto &str : s1)
                if (s2.find(str) != s2.end()) return false;
        } else {
            for (auto &str : s2)
                if (s1.find(str) != s1.end()) return false;
        }
        return true;
    }
};

int main(void)
{
    Solution s;
    s.check();
    return 0;
}
