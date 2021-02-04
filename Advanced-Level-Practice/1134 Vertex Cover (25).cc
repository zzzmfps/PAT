#include <iostream>
#include <vector>
using namespace std;

struct Vertex
{
    int degree = 0;
    vector<int> vertices;
};

class Solution
{
public:
    void vertexCover()
    {
        int nv, ne;
        cin >> nv >> ne;
        vector<Vertex> graph(nv + 1);
        while (ne--) {
            int a, b;
            cin >> a >> b;
            ++graph[a].degree;
            ++graph[b].degree;
            graph[a].vertices.push_back(b);
            graph[b].vertices.push_back(a);
        }

        int k;
        cin >> k;
        while (k--) {
            int x, y;
            cin >> x;
            int *degrees = new int[nv + 1];
            for (int i = 1; i <= nv; ++i) degrees[i] = graph[i].degree;
            while (x--) {
                cin >> y;
                degrees[y] = 0;
                for (auto z : graph[y].vertices) degrees[z] -= 1;
            }
            bool flag = true;
            for (int i = 1; i <= nv; ++i) {
                if (degrees[i] > 0) {
                    flag = false;
                    break;
                }
            }
            delete[] degrees;
            cout << (flag ? "Yes" : "No") << '\n';
        }
    }
};

int main(void)
{
    Solution s;
    s.vertexCover();
    return 0;
}
