#include <iostream>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Money
{
  private:
    long long money;
    static const int G2S = 17;
    static const int S2K = 29;
    static const int G2K = 493;

  public:
    Money()
    {
        int tmp;
        (cin >> tmp).get();
        money = tmp * G2S;
        (cin >> tmp).get();
        money = (tmp + money) * S2K;
        (cin >> tmp).get();
        money += tmp;
    }

    void plus(Money &p) { money += p.money; }

    void output() { cout << money / G2K << '.' << money / S2K % G2S << '.' << money % S2K; }
};

int main(void)
{
    Money a, b;
    a.plus(b);
    a.output();
    system("pause");
    return 0;
}
