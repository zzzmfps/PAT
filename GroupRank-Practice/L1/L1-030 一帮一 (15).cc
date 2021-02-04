#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<pair<int, string>> female, male;
    for (int i = 0; i < n; ++i) {
        int sex;
        string name;
        cin >> sex >> name;
        (sex == 0 ? female : male).emplace_back(i, name);
    }
    int pf1 = 0, pf2 = female.size() - 1, pm1 = 0, pm2 = male.size() - 1;
    for (int i = 0; i < n; i += 2) {
        if (female[pf1].first < male[pm1].first) { // girl + boy
            cout << female[pf1++].second << ' ' << male[pm2--].second << '\n';
        } else { // boy + girl
            cout << male[pm1++].second << ' ' << female[pf2--].second << '\n';
        }
    }
    return 0;
}
