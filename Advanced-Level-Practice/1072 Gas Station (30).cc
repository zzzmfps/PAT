#include <iomanip>
#include <iostream>
#include <utility>
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
    const int LIMIT = 0x3FFFFFFF;
    int n, m, k, ds;
    vector<pair<int, int>> *distances;
    int index, minDist, totalDist;

  public:
    Solution()
    {
        cin >> n >> m >> k >> ds;

        distances = new vector<pair<int, int>>[n + m + 1];
        for (int i = 0; i < k; ++i) {
            int beg, end, len;
            getNumber(beg);
            getNumber(end);
            cin >> len;
            distances[beg].emplace_back(end, len);
            distances[end].emplace_back(beg, len);
        }

        index = -1, minDist = 0, totalDist = LIMIT;
    }

    ~Solution() { delete[] distances; }

    void findBestLocation()
    {
        for (int i = n + 1, num = n + m; i <= num; ++i) {
            int minimum = LIMIT, total = 0;
            if (dijkstra(i, minimum, total))
                if (minimum > minDist || minimum == minDist && total < totalDist)
                    index = i, minDist = minimum, totalDist = total;
        }

        if (index < 0) {
            cout << "No Solution";
        } else {
            cout << 'G' << index - n << '\n';
            cout << fixed << setprecision(1) << double(minDist) << ' ' << totalDist / double(n) + 0.000001;
        }
    }

  private:
    bool dijkstra(int x, int &minimum, int &total)
    {
        bool *isVisited = new bool[n + m + 1]{};
        int *dist = new int[n + m + 1];
        fill(dist + 1, dist + n + m + 1, LIMIT);
        dist[x] = 0;

        for (int i = 1, num = n + m; i <= num; ++i) {
            int u = -1, minLen = LIMIT;
            for (int j = 1; j <= num; ++j)
                if (!isVisited[j] && dist[j] < minLen) u = j, minLen = dist[j];
            isVisited[u] = true;
            for (int k = 0, size = distances[u].size(); k < size; ++k) {
                auto &p = distances[u][k];
                if (!isVisited[p.first]) {
                    int newDist = dist[u] + p.second;
                    if (newDist < dist[p.first]) dist[p.first] = newDist;
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (dist[i] > ds) return false;
            if (dist[i] < minimum) minimum = dist[i];
            total += dist[i];
        }
        return true;
    }

    void getNumber(int &x)
    {
        cin.get();
        if (cin.get() == 'G') {
            cin >> x;
            x += n;
        } else {
            cin.unget();
            cin >> x;
        }
    }
};

int main(void)
{
    Solution s;
    s.findBestLocation();
    return 0;
}
