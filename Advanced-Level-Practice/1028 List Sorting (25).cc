#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    struct Student {
        int id, grade;
        string name;
        Student(int i, string n, int g) : id(i), name(n), grade(g) {}
    };
    vector<Student> info;
    int sortMode;

  public:
    Solution()
    {
        int n;
        cin >> n >> sortMode;
        while (n--) {
            int i, g;
            string n;
            cin >> i >> n >> g;
            info.emplace_back(i, n, g);
        }
        // if write the sort-rule as a funtion, it should be static-member or non-member.
        // if as a nested struct(class), it has no access to data-member(sortMode here).
        sort(info.begin(), info.end(), [this](const Student &x, const Student &y) {
            if (sortMode == 1) {
                return x.id < y.id;
            } else if (sortMode == 2) {
                return x.name < y.name || x.name == y.name && x.id < y.id;
            } else {
                return x.grade < y.grade || x.grade == y.grade && x.id < y.id;
            }
        });
    }

    void printResult() const
    {
        cout << setfill('0');
        for (auto it = info.begin(); it != info.end(); ++it) {
            if (it != info.begin()) cout << '\n';
            cout << setw(6) << it->id << ' ' << it->name << ' ' << it->grade;
        }
    }
};

int main(void)
{
    Solution s;
    s.printResult();
    return 0;
}
