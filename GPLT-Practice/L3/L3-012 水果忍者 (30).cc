#include <bits/stdc++.h>

using Point = std::pair<int, int>;
using Points = std::vector<Point>;

class CutFruit {
private:
    enum SHAPE { CONCAVE, COLLINEAR, CONVEX };
    Points uppers, lowers;

public:
    CutFruit() {
        int n, x, y1, y2;
        std::map<int, int> uppers_, lowers_;
        std::cin >> n;
        while (n--) {
            std::cin >> x >> y1 >> y2;
            if (!uppers_.insert(Point(x, y1)).second) uppers_[x] = std::min(y1, uppers_[x]);
            if (!lowers_.insert(Point(x, y2)).second) lowers_[x] = std::max(y2, lowers_[x]);
        }
        this->uppers.insert(this->uppers.begin(), uppers_.begin(), uppers_.end());
        this->lowers.insert(this->lowers.begin(), lowers_.begin(), lowers_.end());
    }

    void process() {
        if (1 == this->uppers.size()) {
            auto &p1 = this->uppers[0];
            std::cout << p1.first << ' ' << p1.second << ' ' << p1.first + 1 << ' ' << p1.second;
            return;
        }
        this->prune(this->uppers, SHAPE::CONCAVE);
        this->prune(this->lowers, SHAPE::CONVEX);
        auto res = this->getPair(this->uppers, this->lowers, SHAPE::CONVEX);
        if (INT_MAX == res.first.first) res = this->getPair(this->lowers, this->uppers, SHAPE::CONCAVE);
        std::cout << res.first.first << ' ' << res.first.second << ' ' << res.second.first << ' ' << res.second.second;
    }

private:
    void prune(Points &cont, SHAPE correct) {
        int *st = new int[cont.size()]{0, 1}, top = 1; // monostack
        for (int i = 2; i < cont.size(); ++i) {
            for (; top > 0; --top) {
                auto shape = this->checkShape(cont[st[top - 1]], cont[st[top]], cont[i]);
                if (correct == shape) break;
            }
            st[++top] = i;
        }
        Points tmp(1 + top);
        for (int i = 0; i <= top; ++i) tmp[i] = cont[st[i]];
        cont.swap(tmp);
        delete[] st;
    }

    std::pair<Point, Point> getPair(const Points &line1, const Points &line2, SHAPE wrong) {
        for (int i = 1, j; i < line1.size(); ++i) {
            for (j = 0; j < line2.size(); ++j) {
                auto shape = this->checkShape(line1[i - 1], line2[j], line1[i]);
                if (wrong == shape) break;
            }
            if (j == line2.size()) return std::make_pair(line1[i - 1], line1[i]);
        }
        return std::make_pair(Point(INT_MAX, 0), Point());
    }

    SHAPE checkShape(const Point &p1, const Point &p2, const Point &p3) {
        auto t1 = static_cast<long long>(p2.second - p1.second) * (p3.first - p2.first);
        auto t2 = static_cast<long long>(p2.first - p1.first) * (p3.second - p2.second);
        return (t1 == t2 ? SHAPE::COLLINEAR : t1 < t2 ? SHAPE::CONCAVE : SHAPE::CONVEX);
    }
};

int main(int argc, char const *argv[]) {
    CutFruit cf;
    cf.process();
    return 0;
}
