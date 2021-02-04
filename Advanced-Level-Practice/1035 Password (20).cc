#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

static unordered_map<char, char> change = {{'1', '@'}, {'0', '%'}, {'l', 'L'}, {'O', 'o'}};

int main(void)
{
    int accounts;
    cin >> accounts;
    vector<pair<string, string>> modified;
    for (int i = 0; i < accounts; ++i) {
        string id, pwd;
        cin >> id >> pwd;
        bool isModified = false;
        for (auto &p : pwd)
            if (change.find(p) != change.end()) {
                p = change[p];
                isModified = true;
            }
        if (isModified) modified.emplace_back(id, pwd);
    }
    if (modified.empty()) {
        cout << "There " << (accounts == 1 ? "is " : "are ") << accounts << " account" << (accounts == 1 ? "" : "s")
             << " and no account is modified";
    } else {
        cout << modified.size();
        for (const auto &m : modified) cout << '\n' << m.first << ' ' << m.second;
    }
    system("pause");
    return 0;
}
