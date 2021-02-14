#include <bits/stdc++.h>
using namespace std;

using Point = pair<double, double>;

class FlagPieces {
public:
    void process() const {
        int count;
        cin >> count;
        while (count--) cout << (check() ? "YES" : "NO") << '\n';
    }

private:
    bool check() const {
        auto part1 = getPiece(), part2 = getPiece();
        int _min = part1.size(), _max = part2.size();
        if (_min > _max) swap(_min, _max);
        if (_min < 3 || _max > 5 || _min + _max > 8) return false;

        auto edge1 = getEdges(part1), edge2 = getEdges(part2);
        _min = edge1.size(), _max = edge2.size();
        if (_min > _max) swap(_min, _max);
        if (0 == _min) return false;
        if (2 == _min) return 2 == _max && 4 != unordered_set<double>{edge1[0], edge1[1], edge2[0], edge2[1]}.size();
        for (int i = 0; i < 3; ++i)
            if (edge1[i] != edge2[i]) return false;
        if (4 == part1.size() && 4 == part2.size()) return edge1[3] == edge2[3];
        return true;
    }

    vector<Point> getPiece() const {
        int n;
        cin >> n;
        vector<Point> res(n);
        while (n--) cin >> res[n].first >> res[n].second;
        return move(res);
    }

    vector<double> getEdges(const vector<Point> &piece) const {
        int count = 0, x, y;
        for (int i = piece.size() - 1; i >= 0; --i) {
            int j = (i + 1) % piece.size();
            if (piece[i].first != piece[j].first && piece[i].second != piece[j].second) {
                ++count;
                x = i, y = j;
            }
        }
        if (count > 1) { // impossible
            return vector<double>();
        } else if (0 == count) { // a rectangular
            double recEdge1 = abs(piece[0].first - piece[2].first);
            double recEdge2 = abs(piece[0].second - piece[2].second);
            return vector<double>{recEdge1, recEdge2};
        }
        Point newPoint = {piece[x].first, piece[y].second}; // or {i.second, j.first}
        vector<double> edge = {distance(piece[x], piece[y]), distance(piece[x], newPoint),
                               distance(piece[y], newPoint)};
        sort(edge.begin(), edge.end());
        if (4 == piece.size()) {
            int x1 = (x + 2) % piece.size(), y1 = (y + 2) % piece.size();
            edge.push_back(distance(piece[x1], piece[y1]));
        }
        return edge;
    }

    double distance(const Point &point1, const Point &point2) const {
        double diffX = point1.first - point2.first;
        double diffY = point1.second - point2.second;
        if (0 == diffX) return abs(diffY);
        if (0 == diffY) return abs(diffX);
        return sqrt(diffX * diffX + diffY * diffY);
    }
};

int main(int argc, char const *argv[]) {
    FlagPieces fp;
    fp.process();
    return 0;
}
