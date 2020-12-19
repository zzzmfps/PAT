#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    struct Person {
        char gender;
        int father, mother;
        Person(char g = 'A', int f = -1, int m = -1) : gender(g), father(f), mother(m) {}
    } record[100000];

public:
    Solution()
    {
        int n;
        cin >> n;
        while (n--) {
            int idx, fa, mo;
            char gender;
            cin >> idx >> gender >> fa >> mo;
            record[idx] = Person(gender, fa, mo);
            record[fa].gender = 'M', record[mo].gender = 'F'; // important
        }
    }

    void checkRelations()
    {
        int m, idx1, idx2;
        cin >> m;
        while (m--) {
            cin >> idx1 >> idx2;
            if (record[idx1].gender == record[idx2].gender) {
                cout << "Never Mind\n";
            } else {
                cout << (helper(idx1, idx2) ? "Yes" : "No") << '\n';
            }
        }
    }

private:
    bool helper(int x, int y)
    {
        int count = 0;
        unordered_set<int> us;
        queue<int> q;
        q.push(x), q.push(y);
        for (int i = 0; i < 4; ++i) {
            for (int i = q.size(); i > 0; --i) {
                int tmp = q.front();
                int f = record[tmp].father, m = record[tmp].mother;
                if (f != -1) us.insert(f), q.push(f), ++count;
                if (m != -1) us.insert(m), q.push(m), ++count;
                q.pop();
            }
        }
        return count == us.size();
    }
};

int main(void)
{
    Solution s;
    s.checkRelations();
    return 0;
}
