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
    int s0, s1, s2, n;
    vector<vector<string>> chs;

  public:
    Solution()
    {
        chs.resize(3);
        for (int i = 0; i < 3; ++i) getOneLine(chs[i]);
        s0 = chs[0].size(), s1 = chs[1].size(), s2 = chs[2].size();
        cin >> n;
    }

    void printFaces()
    {
        int choices[5];
        while (n--) {
            for (int i = 0; i < 5; ++i) cin >> choices[i];
            if (choices[0] >= s0 || choices[1] >= s1 || choices[2] >= s2 || choices[3] >= s1 || choices[4] >= s0 ||
                choices[0] < 1 || choices[1] < 1 || choices[2] < 1 || choices[3] < 1 || choices[4] < 1) {
                cout << R"(Are you kidding me? @\/@)" << '\n';
            } else {
                cout << chs[0][choices[0]] << '(' << chs[1][choices[1]] << chs[2][choices[2]] << chs[1][choices[3]]
                     << ')' << chs[0][choices[4]] << '\n';
            }
        }
    }

  private:
    void getOneLine(vector<string> &x)
    {
        x.reserve(11);
        x.push_back("");
        while (cin.peek() != '\n') {
            if (cin.get() != '[') continue;
            x.push_back("");
            getline(cin, x.back(), ']');
        }
        cin.get();
        x.shrink_to_fit();
    }
};

int main(void)
{
    Solution s;
    s.printFaces();
    return 0;
}
