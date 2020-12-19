#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int num, payment;
    vector<int> coins;

public:
    Solution()
    {
        cin >> num >> payment;
        coins.resize(num);
        for (int i = 0; i < num; ++i) cin >> coins[i];
        sort(coins.begin(), coins.end());
    }

    void makeChange()
    {
        vector<int> res; // index of coins
        if (helper(res)) {
            cout << coins[res[0]];
            for (int i = 1; i < res.size(); ++i) cout << ' ' << coins[res[i]];
        } else {
            cout << "No Solution";
        }
    }

private:
    bool helper(vector<int> &res)
    { // dfs using iteration, TLE with recursion
        int idx = 0, target = payment;
        while (true) {
            if (0 == target) return true; // get solution
            while (idx == num || coins[idx] > target) {
                // every coins larger than `payment`, or sum of coins less than `payment`
                if (res.empty() || res.size() == num) return false;
                idx = res.back() + 1, target += coins[res.back()]; // roll back
                res.pop_back();
            }
            res.push_back(idx);
            target -= coins[idx++];
        }
        return false;
    }
};

int main(void)
{
    Solution s;
    s.makeChange();
    return 0;
}
