#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int time2int(const string &s)
{
    return 600 * (s[0] - 48) + 60 * (s[1] - 48) + 10 * (s[3] - 48) + s[4] - 48;
}

int main(void)
{
    int days;
    (cin >> days).get();
    for (int i = 0; i < days; ++i) {
        int books = 0, minutes = 0;
        unordered_map<int, int> record;
        while (cin.peek() != '0') {
            int idx;
            char type;
            string time;
            (cin >> idx >> type >> time).get();
            if (type == 'S') { // type S
                // insert new one, or overwrite old incomplete record
                record[idx] = time2int(time);
            } else if (record.find(idx) != record.end()) { // type E, exists S record
                books += 1;
                minutes += time2int(time) - record[idx];
                record.erase(idx);
            }
        }
        cin.ignore(20, '\n');
        cout << books << ' ' << (books ? int(0.5 + minutes / double(books)) : 0) << '\n';
    }
    return 0;
}
