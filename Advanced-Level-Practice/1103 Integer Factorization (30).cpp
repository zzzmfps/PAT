#include <cmath>
#include <iostream>
#include <numeric>
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
    int num, k, power;
    vector<vector<int>> res;
    vector<int> sol;

  public:
    Solution() { cin >> num >> k >> power; }

    void getKPFactorization()
    {
        dfs(num, k, int(pow(num - k + 1, 1.0 / power)));
        if (res.empty()) {
            cout << "Impossible";
        } else {
            int index = maxSequence(), size = res[index].size();
            cout << num << " = " << res[index][0] << '^' << power;
            for (int i = 1; i < size; ++i) cout << " + " << res[index][i] << '^' << power;
        }
    }

  private:
    void dfs(int left, int kn, int base)
    {
        if (kn == 0 || base == 0) return;
        int tmp = pow(base, power);
        if (tmp * kn < left) return;

        if (tmp == left) {
            if (kn == 1) {
                sol.push_back(base);
                res.push_back(sol);
                sol.pop_back();
            }
        } else if (tmp < left) {
            sol.push_back(base);
            dfs(left - tmp, kn - 1, base);
            sol.pop_back();
        }
        dfs(left, kn, base - 1);
    }

    int maxSequence()
    {
        int sum = 0, index, size = res.size();
        for (int i = 0; i < size; ++i) {
            int tmp = accumulate(res[i].begin(), res[i].end(), 0);
            if (tmp > sum) {
                index = i;
                sum = tmp;
            }
        }
        return index;
    }
};

int main(void)
{
    Solution s;
    s.getKPFactorization();
    return 0;
}
