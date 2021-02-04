#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string a;
    bool diff[128] = {};
    getline(cin, a);
    while (cin.peek() != '\n') diff[cin.get()] = true;
    for (auto c : a)
        if (!diff[c]) cout << c;
    return 0;
}
