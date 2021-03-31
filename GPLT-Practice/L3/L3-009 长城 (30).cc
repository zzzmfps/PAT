#include <bits/stdc++.h>
using namespace std;

/** For each power, slopes must be an non-increase array.
 *
 * Note that greedy method may fail on case 5, where the Great Wall is like
 * a letter 'W', that the observation field of the tower is not consecutive.
 *
 * MonoStack: a kind of stack with the following two characteristics:
 * * 1, elements in stack are monotonous
 * * 2, in the increasing (decreasing) stack, a smaller (larger) element can
 *         always be found, in the right of left hand of the given element
 */
using Tower = pair<int, int>;
constexpr double DOUBLE_MAX = numeric_limits<double>::max();

class GreatWall {
private:
    vector<Tower> points;

public:
    GreatWall() {
        int n, x, y;
        cin >> n;
        while (n--) {
            cin >> x >> y;
            this->points.emplace_back(x, y);
        }
    }

    void process() const {
        const int size = this->points.size();

        vector<int> st(size);
        st[0] = 0, st[1] = 1;
        set<int> towers;
        towers.insert(0);

        int top = 1;
        for (int i = 2; i < size; ++i) {
            while (top > 0 && this->isConcave(st[top - 1], st[top], i)) --top; // check and pop
            if (st[top]) towers.insert(st[top]);
            st[++top] = i; // push new element to monoStack
        }
        cout << towers.size() - 1;
    }

private:
    double isConcave(int i, int j, int k) const {
        const auto &a = this->points[i];
        const auto &b = this->points[j];
        const auto &c = this->points[k];
        const double slope1 = 1.0 * (a.second - b.second) / (a.first - b.first);
        const double slope2 = 1.0 * (a.second - c.second) / (a.first - c.first);
        return slope1 >= slope2;
    }
};

int main(void) {
    GreatWall gw;
    gw.process();
    return 0;
}
