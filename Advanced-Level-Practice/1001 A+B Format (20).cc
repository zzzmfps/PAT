#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;
    int c = a + b;
    string s = to_string(abs(c));
    string signal = c < 0 ? "-" : "";
    for (int i = s.size() % 3; i < s.size(); i += 3)
        if (i)
            s.insert(i++, ",");
    cout << signal + s;
    return 0;
}
