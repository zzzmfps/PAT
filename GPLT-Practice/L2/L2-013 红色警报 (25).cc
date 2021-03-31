#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int cities, roads;
    vector<vector<bool>> graph;

public:
    Solution()
    {
        cin >> cities >> roads;
        graph = vector<vector<bool>>(cities, vector<bool>(cities));
        for (int i = 0, c1, c2; i < roads; ++i) {
            cin >> c1 >> c2;
            graph[c1][c2] = graph[c2][c1] = true;
        }
    }

    void redAlert()
    {
        int losts;
        cin >> losts;
        for (int i = 0, lost; i < losts; ++i) {
            cin >> lost;
            vector<int> neighbours;
            for (int j = 0; j < cities; ++j) // find neighbour cities
                if (graph[lost][j]) neighbours.push_back(j);
            for (auto n : neighbours) graph[lost][n] = graph[n][lost] = false; // cut roads
            vector<bool> isVisited(cities);
            if (!neighbours.empty()) bfs(neighbours[0], isVisited); // try to traverse neighbours if exist
            if (all_of(neighbours.begin(), neighbours.end(), [&](int n) { return isVisited[n]; })) {
                // still connects or no neighbour exists
                cout << "City " << lost << " is lost.\n";
            } else {
                cout << "Red Alert: City " << lost << " is lost!\n";
            }
        }
        if (losts == cities) cout << "Game Over.";
    }

private:
    void bfs(int start, vector<bool> &isVisited)
    { // check whether connected cities are divided into more than one part
        vector<int> vec = {start};
        isVisited[start] = true;
        while (!vec.empty()) {
            int cur = vec.back();
            vec.pop_back();
            for (int i = 0; i < cities; ++i) {
                if (!isVisited[i] && graph[cur][i]) {
                    vec.push_back(i);
                    isVisited[i] = true;
                }
            }
        }
    }
};

int main(void)
{
    Solution s;
    s.redAlert();
    return 0;
}
