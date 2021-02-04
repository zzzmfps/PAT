#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

class Solution
{
public:
    void hashingAverageSearchTime()
    {
        int msize, ninsert, nfind;
        cin >> msize >> ninsert >> nfind;
        msize = findNextPrime(msize);
        int *hashTable = new int[msize] {};
        for (int i = 0, v; i < ninsert; ++i) {
            cin >> v;
            int j, k;
            for (k = 0; k < msize; ++k) {
                j = (v + k * k) % msize;
                if (hashTable[j] == 0) {
                    hashTable[j] = v;
                    break;
                }
            }
            if (k == msize) cout << v << " cannot be inserted.\n";
        }
        int cntFind = 0;
        for (int i = 0, v; i < nfind; ++i) {
            cin >> v;
            int j, k;
            for (k = 0; k <= msize; ++k) {
                j = (v + k * k) % msize;
                cntFind += 1;
                if (hashTable[j] == v || hashTable[j] == 0) break;
            }
        }
        cout << fixed << setprecision(1) << double(cntFind) / nfind;
        delete[] hashTable;
    }

private:
    int findNextPrime(int n)
    {
        if (n < 4) return max(2, n);
        while (true) {
            bool isPrime = true;
            for (int i = sqrt(n); i > 1; --i) {
                if (n % i == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) return n;
            n += 1;
        }
    }
};

int main(void)
{
    Solution s;
    s.hashingAverageSearchTime();
    return 0;
}
