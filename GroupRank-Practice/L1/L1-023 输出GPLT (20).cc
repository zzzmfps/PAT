#include <iostream>
using namespace std;

static const char letters[] = {'G', 'P', 'L', 'T'};

int main(void)
{
    int counts[] = {0, 0, 0, 0}, all = 0;
    char ch;
    while ((ch = cin.get()) != '\n') {
        switch (ch) {
            case 'g':
            case 'G': ++counts[0], ++all; break;
            case 'p':
            case 'P': ++counts[1], ++all; break;
            case 'l':
            case 'L': ++counts[2], ++all; break;
            case 't':
            case 'T': ++counts[3], ++all; break;
            default: break;
        }
    }
    while (all) {
        for (int i = 0; i < 4; ++i) {
            if (counts[i]) {
                cout << letters[i];
                --counts[i], --all;
            }
        }
    }
    return 0;
}
