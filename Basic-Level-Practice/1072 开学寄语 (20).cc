#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    void check()
    {
        int n, m, stu = 0, items = 0;
        cin >> n >> m;
        vector<int> forbiddens(m);
        while (m--) cin >> forbiddens[m];
        while (n--) {
            string name;
            int k, id;
            cin >> name >> k;
            vector<int> confiscated;
            while (k--) {
                cin >> id;
                if (find(forbiddens.begin(), forbiddens.end(), id) != forbiddens.end()) confiscated.push_back(id);
            }
            if (!confiscated.empty()) {
                stu += 1, items += confiscated.size();
                cout << name << ':';
                for (auto c : confiscated) cout << ' ' << setw(4) << setfill('0') << c;
                cout << '\n';
            }
        }
        cout << stu << ' ' << items << '\n';
    }
};

int main(void)
{
    Solution s;
    s.check();
    return 0;
}
