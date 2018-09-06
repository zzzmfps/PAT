#include <iostream>
#include <unordered_map>
#include <utility>
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
    int k;
    string str;
    vector<pair<char, int>> vec;
    unordered_map<char, bool> status;

  public:
    Solution()
    {
        (cin >> k).get();
        getline(cin, str);
        for (int i = 0, len = str.size(); i < len; ++i) {
            int j = 1;
            while (str[i + 1] == str[i]) ++i, ++j;
            vec.emplace_back(str[i], j);
            status[str[i]] = (j >= k && j % k == 0 ? true : false);
        }
    }

    void getOriginalString()
    {
        bool *isPrinted = new bool[128]{};
        for (auto &p : vec) {
            if (status[p.first]) {
                p.second /= k;
                if (!isPrinted[p.first]) {
                    cout << p.first;
                    isPrinted[p.first] = true;
                }
            }
        }
        cout << '\n';
        delete[] isPrinted;

        for (const auto &p : vec)
            for (int i = 0; i < p.second; ++i) cout << p.first;
    }
};

int main(void)
{
    Solution s;
    s.getOriginalString();
    return 0;
}
