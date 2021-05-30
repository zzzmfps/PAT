#include <bits/stdc++.h>

using ULL = unsigned long long;

class RemoveChars {
public:
    static ULL subStringNums(const std::string &str) {
        ULL ne01 = (str[0] != str[1]);
        ULL ne02 = (str[0] != str[2]);
        ULL ne12 = (str[1] != str[2]);

        std::vector<ULL *> dp(5);
        dp[0] = new ULL[4]{1, 0, 0, 0};
        dp[1] = new ULL[4]{1, 1, 0, 0};
        dp[2] = new ULL[4]{1, 1 + ne01, 1, 0};
        dp[3] = new ULL[4]{1, 1 + ne01 + ne12, 1 + ne01 + (ne02 & ne12), 1};
        dp[4] = new ULL[4]{1};

        for (size_t i = 3; i < str.size(); ++i) {
            for (size_t j = 1; j <= 3; ++j) {
                dp[4][j] = dp[3][j - 1] + dp[3][j];
                for (size_t k = 1; k <= j; ++k) {
                    if (str[i] == str[i - k]) {
                        dp[4][j] -= dp[3 - k][j - k];
                        break;
                    }
                }
            }
            for (size_t i = 1; i < dp.size(); ++i) std::swap(dp[i - 1], dp[i]);
        }
        return RemoveChars::done(dp);
    }

private:
    static ULL done(std::vector<ULL *> &v) {
        size_t resIndex = v.size() - 2;
        ULL res = std::accumulate(v[resIndex], v[resIndex] + 4, 0ULL); // NOT 0
        for (auto &&ptr : v) delete[] ptr;
        return res;
    }
};

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << RemoveChars::subStringNums(str);
    return 0;
}
