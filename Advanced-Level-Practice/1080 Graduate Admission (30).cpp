#include <algorithm>
#include <iostream>
#include <map>
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
    struct Applicant {
        int order;
        int ge, gi, total;
        int choice[5];
    };
    struct SortRule {
        bool operator()(const Applicant &x, const Applicant &y) const
        {  // stable sort
            return x.total > y.total || x.total == y.total && x.ge > y.ge;
        }
    };
    int N, M, K, *quota;
    map<int, vector<Applicant>> rank;
    vector<int> *result;

  public:
    Solution()
    {
        cin >> N >> M >> K;
        quota = new int[M];
        for (int i = 0; i < M; ++i) cin >> quota[i];

        vector<Applicant> apps(N);
        for (int i = 0; i < N; ++i) {
            apps[i].order = i;
            cin >> apps[i].ge >> apps[i].gi;
            apps[i].total = apps[i].ge + apps[i].gi;
            for (int j = 0; j < K; ++j) cin >> apps[i].choice[j];
        }
        sort(apps.begin(), apps.end(), SortRule());

        rank[0].push_back(apps[0]);
        for (int i = 1, r = 0; i < N; ++i) {
            if (apps[i].total == apps[i - 1].total && apps[i].ge == apps[i - 1].ge) {
                rank[r].push_back(apps[i]);
            } else {
                rank[++r].push_back(apps[i]);
            }
        }
    }

    ~Solution()
    {
        delete[] quota;
        delete[] result;
    }

    void admit()
    {
        result = new vector<int>[M];
        for (const auto &same : rank) {  // for each rank
            int *curAdmitted = new int[M]();
            for (const auto &app : same.second) {  // for each applicant
                for (int i = 0; i < K; ++i)        // for each choice
                    if (quota[app.choice[i]] > 0) {
                        ++curAdmitted[app.choice[i]];
                        result[app.choice[i]].push_back(app.order);
                        break;
                    }
            }
            for (int i = 0; i < M; ++i) quota[i] -= curAdmitted[i];  // update quota
            delete[] curAdmitted;
        }
    }

    void printResult() const
    {
        for (int i = 0; i < M; ++i) {
            int size = result[i].size();
            if (size > 0) {
                sort(result[i].begin(), result[i].end());
                cout << result[i][0];
                for (int j = 1; j < size; ++j) cout << ' ' << result[i][j];
            }
            // WHY NOT "if (i < M - 1) cout << '\n';" ??? (says format error)
            cout << '\n';  // it will yield an EXTRA empty line at the end.
        }
    }
};

int main(void)
{
    Solution s;
    s.admit();
    s.printResult();
    return 0;
}
