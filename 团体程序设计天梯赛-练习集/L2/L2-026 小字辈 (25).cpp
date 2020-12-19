#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int num;
    vector<int> rec;

public:
    Solution()
    {
        cin >> num;
        rec.resize(num + 1);
        for (int i = 1; i <= num; ++i) cin >> rec[i];
    }

    void check()
    {
        vector<int> tmp(num + 1); // counts
        int _max = 0;             // max count
        vector<int> res;          // max index
        for (int i = 1; i <= num; ++i) {
            int cur = helper(tmp, i);
            if (cur > _max) _max = cur, res.clear();
            if (cur == _max) res.push_back(i);
        }
        cout << _max;
        for (int i = 0; i < res.size(); ++i) cout << (i ? ' ' : '\n') << res[i];
    }

private:
    int helper(vector<int> &tmp, int i)
    {
        if (tmp[i]) return tmp[i];
        if (rec[i] == -1) return tmp[i] = 1;
        return tmp[i] = 1 + helper(tmp, rec[i]);
    }
};

int main(void)
{
    Solution s;
    s.check();
    return 0;
}
