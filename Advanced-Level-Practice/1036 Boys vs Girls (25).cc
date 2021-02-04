#include <iostream>
#include <string>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

struct stu {
    string name, id;
    char gender;
    int score;
};

int main(void)
{
    stu *female = nullptr, *male = nullptr;
    int n;
    cin >> n;
    while (n--) {
        stu *tmp = new stu;
        cin >> tmp->name >> tmp->gender >> tmp->id >> tmp->score;
        if (tmp->gender == 'F') {
            if (!female || tmp->score > female->score) female = tmp;
        } else {
            if (!male || tmp->score < male->score) male = tmp;
        }
    }
    female ? cout << female->name << ' ' << female->id << '\n' : cout << "Absent\n";
    male ? cout << male->name << ' ' << male->id << '\n' : cout << "Absent\n";
    (female && male) ? cout << female->score - male->score : cout << "NA\n";
    system("pause");
    return 0;
}
