#include <iomanip>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
private:
    static const int MAX_STATIONS = 10000;
    unordered_map<int, unordered_map<int, int>> graph;

public:
    Solution()
    {
        int n, m, v1, v2;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> m >> v1;
            while (--m) {
                cin >> v2;
                graph[v1][v2] = graph[v2][v1] = i;
                v1 = v2;
            }
        }
    }

    void subwayMap()
    {   // Rule 1, the path with the minimum number of stops. if not unique, then
        // Rule 2, the path with the minimum number of transfers
        int k, start, dest;
        cin >> k;
        while (k--) {
            cin >> start >> dest;
            auto path = getPaths(start, dest);
            output(path);
        }
    }

private:
    vector<int> getPaths(int start, int dest)
    {
        vector<vector<int>> paths;
        queue<vector<int>> q;
        q.push(vector<int>{start});
        bool *isVisited = new bool[MAX_STATIONS] {};
        isVisited[start] = true;
        while (true) {  // all stations reachable and all queries legal
            bool isFound = false;
            unordered_set<int> newSt;   // record new station this loop
            for (int i = q.size(); i > 0; --i) {
                auto &tmp = q.front();
                if (tmp.back() == dest) {
                    paths.push_back(tmp);
                    isFound = true;
                }
                if (!isFound) { // stop expand when a path is found
                    auto &nexts = graph[tmp.back()];    // next stations
                    for (auto it = nexts.begin(); it != nexts.end(); ++it) {
                        int ns = it->first;
                        if (!isVisited[ns] || ns == dest) {
                            // isVisited will not be set until the loop is done, because
                            // a station can be visited again if length is the same
                            newSt.insert(ns);
                            tmp.push_back(ns);
                            q.push(tmp);
                            tmp.pop_back();
                        }
                    }
                }
                q.pop();
            }
            if (isFound) break;
            for (auto ns : newSt) isVisited[ns] = true;
        }
        delete[] isVisited;

        if (paths.size() == 1) return paths[0];
        int minTransfer = MAX_STATIONS, minIdx = 0;
        for (int i = 0; i < paths.size(); ++i) {    // select one according to Rule 2
            int count = 0;
            for (int j = 1, lastLine = 0; j < paths[i].size(); ++j) {
                int pres = paths[i][j - 1], curs = paths[i][j];
                if (graph[pres][curs] != lastLine) count += 1;
                lastLine = graph[pres][curs];
            }
            if (count < minTransfer) {
                minTransfer = count;
                minIdx = i;
            }
        }
        return paths[minIdx];
    }

    void output(const vector<int> &path)
    {
        cout << path.size() - 1 << '\n' << setfill('0');
        bool transfer = true;
        for (int i = 1; i < path.size(); ++i) {
            if (transfer) { // start station, or the beginning station of the transfer
                cout << "Take Line#" << graph[path[i - 1]][path[i]] << " from " << setw(4) << path[i - 1] << " to ";
                transfer = false;
            }
            // skip stations that are neither destination nor transfer
            if (i + 1 < path.size() && graph[path[i - 1]][path[i]] == graph[path[i]][path[i + 1]]) continue;
            cout << setw(4) << path[i] << ".\n";
            transfer = true;
        }
    }
};

int main(void)
{
    Solution s;
    s.subwayMap();
    return 0;
}
