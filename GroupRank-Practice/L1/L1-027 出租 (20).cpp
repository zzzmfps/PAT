#include <iostream>
using namespace std;

int main(void)
{
    string phone;
    cin >> phone;
    bool digits[10] = {};  // is it exists
    for (auto c : phone) digits[c - 48] = true;

    string arr = "int[] arr = new int[]{";
    int tmp[10] = {}, j = 0;  // index sorted by descending
    for (int i = 9; i > -1; --i)
        if (digits[i]) arr.append({char(48 + i), ','}), tmp[i] = ++j;
    arr.back() = '}', arr += ';';

    string index = "int[] index = new int[]{";
    for (auto c : phone) index.append({char(47 + tmp[c - 48]), ','});
    index.back() = '}', index += ';';

    cout << arr << '\n' << index;
    return 0;
}
