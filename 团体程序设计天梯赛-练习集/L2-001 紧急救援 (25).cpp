#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    const int INF = 0x3F3F3F3F;
    int cities, roads, start, dest;
    vector<int> rescue;        // num of rescue in each city
    vector<vector<int>> graph; // graph of roads
    // result
    vector<int> counts; // num of shortest path
    vector<int> mteams; // max rescue teams when arrived at each city
    vector<int> prevRt; // best shortest path

public:
    Solution()
    {
        cin >> cities >> roads >> start >> dest;
        rescue.resize(cities);
        for (int i = 0; i < cities; ++i) cin >> rescue[i];
        graph = vector<vector<int>>(cities, vector<int>(cities, INF));
        for (int i = 0, s, e, l; i < roads; ++i) {
            cin >> s >> e >> l;
            graph[s][e] = graph[e][s] = l;
        }
        counts.resize(cities);
        counts[start] = 1; // initial it as counts.resize(cities, 1) is not right
        mteams.resize(cities);
        mteams[start] = rescue[start];
        prevRt.resize(cities, -1);
        prevRt[start] = start;
    }

    void dijkstra()
    { // standard dijkstra procedure
        vector<bool> isVisited(cities, false);
        vector<int> length(cities, INF); // length of road from start to each city
        length[start] = 0;
        for (int i = 0; i < cities; ++i) {
            int u = -1, minLen = INF;
            for (int j = 0; j < cities; ++j) {
                if (isVisited[j] || length[j] >= minLen) continue;
                u = j, minLen = length[j];
            }
            isVisited[u] = true;               // arrived at city u
            for (int k = 0; k < cities; ++k) { // update path info from city u
                if (graph[u][k] == INF) continue;
                int newDist = length[u] + graph[u][k], newTeam = mteams[u] + rescue[k];
                if (newDist < length[k]) {
                    length[k] = newDist;
                    counts[k] = counts[u];
                    mteams[k] = newTeam;
                    prevRt[k] = u;
                } else if (newDist == length[k]) {
                    counts[k] += counts[u]; // update counts before check num of teams
                    if (newTeam > mteams[k]) {
                        mteams[k] = newTeam;
                        prevRt[k] = u;
                    }
                }
            }
        }
        cout << counts[dest] << ' ' << mteams[dest] << '\n';
        printPath(dest);
    }

private:
    void printPath(int x)
    {
        if (x != prevRt[x]) printPath(prevRt[x]);
        cout << x << (x == dest ? '\n' : ' ');
    }
};

int main(void)
{
    Solution s;
    s.dijkstra();
    return 0;
}
