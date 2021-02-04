#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
private:
    struct User {
        string name;
        int all, diff = 0;
    };
    vector<User> list;

public:
    int thumbUpLovers()
    {
        int n;
        cin >> n;
        list.resize(n);
        while (n--) {
            cin >> list[n].name >> list[n].all;
            unordered_set<int> us;
            for (int i = 0, tag; i < list[n].all; ++i) {
                cin >> tag;
                if (us.find(tag) == us.end()) {
                    list[n].diff += 1;
                    us.insert(tag);
                }
            }
        }
        sort(list.begin(), list.end(), [](const User &x, const User &y) {
            return x.diff > y.diff || x.diff == y.diff && x.diff / double(x.all) > y.diff / double(y.all);
        });
        cout << list[0].name;
        cout << ' ' << (list.size() > 1 ? list[1].name : "-");
        cout << ' ' << (list.size() > 2 ? list[2].name : "-");
    }
};

int main(void)
{
    Solution s;
    s.thumbUpLovers();
    return 0;
}
