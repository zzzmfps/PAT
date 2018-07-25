#include <iomanip>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    unordered_map<string, set<int>> books[5];

  public:
    Solution()
    {
        int n, id;
        string str;
        cin >> n;
        while (n--) {
            (cin >> id).get();
            for (int i = 0; i < 2; ++i) {
                getline(cin, str);
                books[i][str].insert(id);
            }
            while (cin >> str) {
                books[2][str].insert(id);
                if (cin.get() == '\n') break;
            }
            for (int i = 3; i < 5; ++i) {
                getline(cin, str);
                books[i][str].insert(id);
            }
        }
    }

    void query()
    {
        int m, type;
        cin >> m;
        string str;
        cout << setfill('0');
        while (m--) {
            (cin >> type).ignore(2);
            getline(cin, str);
            cout << type-- << ": " << str << '\n';
            if (books[type].find(str) == books[type].end()) {
                cout << "Not Found\n";
                continue;
            }
            for (const auto &v : books[type][str]) cout << setw(7) << v << '\n';
        }
    }
};

int main(void)
{
    Solution s;
    s.query();
    return 0;
}
