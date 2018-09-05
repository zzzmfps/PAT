#include <algorithm>
#include <iomanip>
#include <iostream>
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
    struct Pairs {
        int arrive, play;  // both seconds
        Pairs(int a, int p) : arrive(a), play(min(7200, 60 * p)) {}
    };
    const int BEG = 28800, END = 75600;  // beg time: 8 hrs, end time: 21 hrs
    int nums, vips, tables, vipTables, *vipIdx;
    bool *isVipTable;
    vector<Pairs> list[2];  // list0 for ordinary, list1 for Vip

  public:
    Solution()
    {
        cin >> nums;

        list[0].reserve(nums);
        list[1].reserve(nums);
        for (int i = 0, h, m, s, p, v; i < nums; ++i) {
            (cin >> h).get();
            (cin >> m).get();
            cin >> s >> p >> v;
            int a = 3600 * h + 60 * m + s;
            // arriving time is guaranteed between 8:00:00 ~ 21:00:00 while club is open,
            // but test point 3 does NOT obey it (after 21:00:00).
            if (a < END) (v == 0 ? list[0] : list[1]).emplace_back(a, p);
        }
        nums = list[0].size(), vips = list[1].size();
        auto rule = [](const Pairs &x, const Pairs &y) { return x.arrive < y.arrive; };
        sort(list[0].begin(), list[0].end(), rule);
        sort(list[1].begin(), list[1].end(), rule);

        cin >> tables >> vipTables;

        isVipTable = new bool[tables + 1]{};
        vipIdx = new int[vipTables];
        for (int i = 0, j; i < vipTables; ++i) {
            cin >> vipIdx[i];
            isVipTable[vipIdx[i]] = true;
        }
    }

    ~Solution() { delete[] isVipTable; }

    void getServingList()
    {
        int *serves = new int[tables + 1];    // end time of each table
        int *counts = new int[tables + 1]{};  // served times of each table
        int idx[2]{};                         // index of ordinary(0) and Vip(1) player-pairs
        fill(serves + 1, serves + tables + 1, BEG);

        auto decide = [&](int i) {  // decide which player-pair to occupy the table
            if (isVipTable[i]) {    // if is table for Vip
                if (idx[0] == nums || idx[1] < vips && (list[1][idx[1]].arrive <= serves[i] ||
                                                        list[1][idx[1]].arrive < list[0][idx[0]].arrive))
                    return 1;
                return 0;
            } else {
                if (idx[0] == nums) return 1;
                if (idx[1] == vips) return 0;
                return list[0][idx[0]].arrive < list[1][idx[1]].arrive ? 0 : 1;
            }
        };
        auto updateAndPrint = [&](int i, int y) {  // update info and print times
            serves[i] = max(serves[i], list[y][idx[y]].arrive);
            printTime(list[y][idx[y]], serves[i]);
            serves[i] += list[y][idx[y]].play;
            ++counts[i], ++idx[y];
        };

        for (int idx3 = 1, idx4 = 0; idx[0] < nums || idx[1] < vips;) {
            while (idx3 <= tables && counts[idx3]) ++idx3;
            if (idx3 > tables) break;
            while (idx4 < vipTables && counts[vipIdx[idx4]]) ++idx4;
            int y = decide(idx4 < vipTables ? 1 : 0);
            updateAndPrint((y == 1 && idx4 < vipTables ? vipIdx[idx4] : idx3), y);
        }
        while (idx[0] < nums || idx[1] < vips) {
            int *minElem = min_element(serves + 1, serves + tables + 1);
            if (*minElem >= END) break;
            int i = minElem - serves;
            updateAndPrint(i, decide(i));
        }
        for (int i = 1; i <= tables; ++i) cout << (i > 1 ? " " : "") << counts[i];

        delete[] serves, counts;
    }

  private:
    void printTime(const Pairs &x, int begin) const
    {
        auto helper = [](int x) {
            cout << setw(2) << x / 3600 << ':' << setw(2) << x % 3600 / 60 << ':' << setw(2) << x % 60 << ' ';
        };
        cout << setfill('0');
        helper(x.arrive);
        helper(begin);
        cout << int((begin - x.arrive) / 60.0 + 0.5) << '\n';
    }
};

int main(void)
{
    Solution s;
    s.getServingList();
    return 0;
}
