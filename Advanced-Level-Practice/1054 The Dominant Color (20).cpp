#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    int m, n, **pixels;

  public:
    Solution()
    {
        cin >> n >> m;
        pixels = new int *[m];
        for (int i = 0; i < m; ++i) {
            pixels[i] = new int[n];
            for (int j = 0; j < n; ++j) cin >> pixels[i][j];
        }
    }

    int getDominantColor()
    {
        int dominant = pixels[0][0], count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                count += (dominant == pixels[i][j] ? 1 : -1);
                if (count == 0) {
                    dominant = pixels[i][j];
                    count = 1;
                }
            }
        }
        return dominant;
    }
};

int main(void)
{
    Solution s;
    cout << s.getDominantColor();
    return 0;
}
