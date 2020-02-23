#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
private:
    int a, b;
    vector<bool> isPrime;

public:
    Solution()
    {
        cin >> a >> b;
        isPrime.resize(b + 1, true);
        for (int i = 2; i <= b; ++i) {
            if (!isPrime[i]) continue;
            for (int j = i << 1; j <= b; j += i) isPrime[j] = false;
        }
    }

    void checkHappyNumber()
    {
        vector<bool> isHappyNumber(b + 1, true);
        vector<int> factors(b + 1);
        for (int i = a; i <= b; ++i) {
            unordered_set<int> us;
            int _next = i;
            while (true) {
                _next = nextNumber(_next);
                if (_next == 1) break;                 // it is happy number
                if (us.find(_next) != us.end()) break; // dead loop
                if (_next >= a && _next <= b) isHappyNumber[_next] = false;
                us.insert(_next);
            }
            if (_next == 1) {
                factors[i] = (1 + us.size()) * (1 + isPrime[i]);
            } else {
                isHappyNumber[i] = false;
            }
        }
        bool flag = false;
        for (int i = a; i <= b; ++i) {
            if (isHappyNumber[i]) {
                cout << i << ' ' << factors[i] << '\n';
                flag = true;
            }
        }
        if (!flag) cout << "SAD";
    }

private:
    int nextNumber(int x)
    {
        int ret = 0;
        while (x) {
            int tmp = x % 10;
            ret += tmp * tmp;
            x /= 10;
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    s.checkHappyNumber();
    return 0;
}
