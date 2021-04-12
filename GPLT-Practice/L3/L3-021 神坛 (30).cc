#include <bits/stdc++.h>

class Triangle {
private:
    using LL = long long; // failed at case 4, 8 if using double
    using Point = std::pair<LL, LL>;
    using Line = std::pair<LL, LL>;
    static constexpr LL INF = std::numeric_limits<LL>::max();

    std::vector<Point> stones;

public:
    Triangle() {
        LL n, x, y;
        std::cin >> n;
        while (n--) {
            std::cin >> x >> y;
            this->stones.emplace_back(x, y);
        }
    }

    double process() {
        LL res = Triangle::INF;
        for (auto i = this->stones.begin(); i != this->stones.end(); ++i) {
            std::vector<Line> v;
            v.reserve(this->stones.size() - 1);
            for (auto j = this->stones.begin(); j != this->stones.end(); ++j) {
                if (i == j) continue;
                if (i->first == j->first && i->second == j->second) return 0.0;
                v.emplace_back(j->first - i->first, j->second - i->second);
            }
            v.shrink_to_fit();

            std::sort(v.begin(), v.end(), [](const Line &l1, const Line &l2) {
                LL pr1 = l1.second * l2.first;
                LL pr2 = l1.first * l2.second;
                if (pr1 != pr2) return pr1 < pr2;
                return l1.first < l2.first;
            });

            for (size_t k = 1; k < v.size(); ++k) {
                LL cross = v[k - 1].first * v[k].second - v[k - 1].second * v[k].first;
                res = std::min(res, std::abs(cross));
            }
            if (0 == res) return 0.0;
        }

        return 0.5 * res;
    }
};

int main() {
    Triangle t;
    std::cout << std::fixed << std::setprecision(3) << t.process() << '\n';
    return 0;
}
