#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
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
    struct Person {
        int father = -1, mother = -1;
        int k = 0, children[5]{-1, -1, -1, -1, -1};
        int sets = 0, area = 0;
    };
    struct Family {
        int id, nums;
        double avgSets, avgArea;
        Family(int i, int n, double s, double a) : id(i), nums(n), avgSets(s), avgArea(a) {}
    };
    int n;
    bool *isVisited;
    Person *people;

  public:
    Solution()
    {
        cin >> n;
        isVisited = new bool[10000];
        fill(isVisited, isVisited + 10000, true);
        people = new Person[10000];
        for (int i = 0, j, x, y, z; i < n; ++i) {
            cin >> j >> x >> y;
            people[j].father = x, people[j].mother = y;
            if (x >= 0 && find(people[x].children, people[x].children + 5, j)==(people[x].children+5)) {
                people[x].children[people[x].k++] = j;
                isVisited[x] = false;
            }
            if (y >= 0 && find(people[y].children, people[y].children + 5, j)==(people[y].children+5)) {
                people[y].children[people[y].k++] = j;
                isVisited[y] = false;
            }
            cin >> people[j].k;
            if (people[j].k)
                for (int l = 0, m; l < people[j].k; ++l) {
                    cin >> m;
                    people[j].children[l] = m;
                    (people[m].father < 0 ? people[m].father : people[m].mother) = j;
                    isVisited[m] = false;
                }
            cin >> people[j].sets >> people[j].area;
            isVisited[j] = false;
        }
    }

    ~Solution()
    {
        delete[] isVisited;
        delete[] people;
    }

    void countFamilyProperty()
    {
        vector<Family> res;
        for (int i = 0; i < 10000; ++i)
            if (!isVisited[i]) bfs(res, isVisited, i);
        sort(res.begin(), res.end(), [](const Family &x, const Family &y) {
            return x.avgArea > y.avgArea || x.avgArea == y.avgArea && x.id < y.id;
        });
        cout << res.size() << '\n' << setfill('0') << fixed << setprecision(3);
        for (const auto &r : res)
            cout << setw(4) << r.id << ' ' << r.nums << ' ' << r.avgSets << ' ' << r.avgArea << '\n';
    }

  private:
    void bfs(vector<Family> &res, bool *isVisited, int i)
    {
        int id = 10000, num = 0, sets = 0, area = 0;
        queue<int> tmp;
        tmp.push(i), isVisited[i] = true;
        while (!tmp.empty()) {
            int x = tmp.front();
            tmp.pop();
            auto &y = people[x];
            id = min(id, x), ++num, sets += y.sets, area += y.area;
            if (y.father != -1 && !isVisited[y.father]) tmp.push(y.father), isVisited[y.father] = true;
            if (y.mother != -1 && !isVisited[y.mother]) tmp.push(y.mother), isVisited[y.mother] = true;
            for (int j = 0; j < y.k; ++j)
                if (y.children[j] != -1 && !isVisited[y.children[j]])
                    tmp.push(y.children[j]), isVisited[y.children[j]] = true;
        }
        res.emplace_back(id, num, sets / double(num), area / double(num));
    }
};

int main(void)
{
    Solution s;
    s.countFamilyProperty();
    return 0;
}
