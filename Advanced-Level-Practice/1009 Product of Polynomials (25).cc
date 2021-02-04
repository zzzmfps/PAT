#include <iomanip>
#include <iostream>
#include <map>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    map<int, double> poly1, poly2;

  public:
    Solution()
    {
        int len1, len2, n;
        double an;
        cin >> len1;
        while (len1--) {
            cin >> n >> an;
            poly1[n] = an;
        }
        cin >> len2;
        while (len2--) {
            cin >> n >> an;
            poly2[n] = an;
        }
    }

    void printProduct()
    {
        map<int, double> product;
        for (auto iter1 = poly1.cbegin(); iter1 != poly1.cend(); ++iter1)
            for (auto iter2 = poly2.cbegin(); iter2 != poly2.cend(); ++iter2)
                product[iter1->first + iter2->first] += iter1->second * iter2->second;
        int size = 0;
        for (const auto &p : product)
            if (p.second) ++size;
        cout << size;
        if (size)
            for (auto iter3 = product.crbegin(); iter3 != product.crend(); ++iter3)
                if (iter3->second)
                    cout << ' ' << iter3->first << ' ' << setiosflags(ios_base::fixed) << setprecision(1)
                         << iter3->second;
    }
};

int main(void)
{
    Solution s = Solution();
    s.printProduct();
    system("pause");
    return 0;
}
