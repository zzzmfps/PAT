#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

class Polynomials
{
  private:
    map<int, double> polys;

  public:
    Polynomials()
    {
        inputPoly();
        inputPoly();
    }

    void outputPoly()
    {
        int size = 0;
        for (auto const &p : polys)
            if (p.second)
                ++size;
        cout << size;
        if (size)
            for (auto it = polys.rbegin(); it != polys.rend(); ++it)
                if ((*it).second)
                    cout << ' ' << (*it).first << ' '
                         << fixed << setprecision(1) << (*it).second;
    }

  private:
    void inputPoly()
    {
        int nums, n;
        double an;
        cin >> nums;
        for (int i = 0; i < nums; ++i)
        {
            cin >> n >> an;
            polys[n] += an;
        }
    }
};

int main(void)
{
    Polynomials p;
    p.outputPoly();
    system("pause");
    return 0;
}
