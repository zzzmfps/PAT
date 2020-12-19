#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string time;
    getline(cin, time);
    cout << time.substr(6) << '-' << time.substr(0, 5);
    return 0;
}
