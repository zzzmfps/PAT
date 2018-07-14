#include <iostream>
#include <map>
#include <string>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    static const int limit = 1000000007;
    map<char, int *> record;
    int countA = 1, size;

  public:
    Solution()
    {
        string tmp;
        getline(cin, tmp);
        size = tmp.size();
        record['P'] = new int[size + 1]{};
        record['A'] = new int[size + 1]{};
        record['T'] = new int[size + 1]{};
        for (int i = 1; i <= size; ++i) {
            char c = tmp[i - 1];
            if (c == 'A') record['A'][countA++] = i;
            record['P'][i] = record['P'][i - 1] + (c == 'P' ? 1 : 0);
            record['T'][i] = record['T'][i - 1] + (c == 'T' ? 1 : 0);
        }
    }

    int getNums()
    {
        int res = 0;
        auto &strA = record['A'];
        for (int i = 1; i < countA; ++i)
            res = (res + record['P'][strA[i]] * (record['T'][size] - record['T'][strA[i]])) % limit;
        return res;
    }
};

int main(void)
{
    Solution s;
    cout << s.getNums();
    return 0;
}
