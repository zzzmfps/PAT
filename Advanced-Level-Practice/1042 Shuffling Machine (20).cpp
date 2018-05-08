#include <iostream>
#include <string>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Shuffle
{
  private:
    string *cards = new string[54]();
    int count, changes[54];

  public:
    Shuffle()
    {
        for (int i = 0; i < 13; ++i) cards[i] = "S" + to_string(i + 1);
        for (int i = 13; i < 26; ++i) cards[i] = "H" + to_string(i - 12);
        for (int i = 26; i < 39; ++i) cards[i] = "C" + to_string(i - 25);
        for (int i = 39; i < 52; ++i) cards[i] = "D" + to_string(i - 38);
        cards[52] = "J1", cards[53] = "J2";
        cin >> count;
        for (int i = 0; i < 54; ++i) cin >> changes[i];
    }

    void printShuffled()
    {
        while (count--) {
            string *tmp = new string[54]();
            for (int i = 0; i < 54; ++i) tmp[changes[i] - 1] = cards[i];
            delete[] cards;
            cards = tmp;
        }
        for (int i = 0; i < 53; ++i) cout << cards[i] << ' ';
        cout << cards[53];
    }
};

int main(void)
{
    Shuffle s = Shuffle();
    s.printShuffled();
    system("pause");
    return 0;
}
