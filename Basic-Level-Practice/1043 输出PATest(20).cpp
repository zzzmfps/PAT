#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    static constexpr char letters[]{'P', 'A', 'T', 'e', 's', 't'};
    int counts[6]{};
    int amount = 0;

  public:
    Solution()
    {
        string tmp;
        cin >> tmp;
        for (const auto c : tmp) {
            switch (c) {
                case 'P': ++counts[0]; break;
                case 'A': ++counts[1]; break;
                case 'T': ++counts[2]; break;
                case 'e': ++counts[3]; break;
                case 's': ++counts[4]; break;
                case 't': ++counts[5];
            }
        }
        for (int i = 0; i < 6; ++i) amount += counts[i];
    }

    void output()
    {
        while (amount)
            for (int i = 0; i < 6; ++i)
                if (counts[i]) {
                    cout << letters[i];
                    --counts[i];
                    --amount;
                }
    }
};

int main(void)
{
    Solution s;
    s.output();
    return 0;
}
