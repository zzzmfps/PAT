#include <bits/stdc++.h>
using namespace std;

class MaskDelivery {
private:
    struct Candidate {
        string name, id, time;
        bool condition;
        int order;
        Candidate(int x) : order(x) {}
    };
    int d, p, cur = 0;
    unordered_map<string, int> history;
    unordered_set<string> recorded;
    vector<Candidate> conditions;

public:
    MaskDelivery() {
        cin >> this->d >> this->p;
    }

    bool dailyCheck() {
        if (++this->cur > this->d) return false;
        int t, s;
        cin >> t >> s;
        vector<Candidate> today;
        today.reserve(t);
        for (int i = 0; i < t; ++i) {
            Candidate candidate = Candidate(i);
            cin >> candidate.name >> candidate.id >> candidate.condition >> candidate.time;
            if (18 != candidate.id.length() ||
                any_of(candidate.id.begin(), candidate.id.end(), [](char x) { return !isdigit(x); })) {
                continue;
            }
            if (candidate.condition && this->recorded.find(candidate.id) == this->recorded.end()) {
                this->conditions.push_back(candidate);
                this->recorded.insert(candidate.id);
            }
            today.push_back(candidate);
        }
        sort(today.begin(), today.end(), [](const Candidate &c1, const Candidate &c2) {
            return c1.time < c2.time || c1.time == c2.time && c1.order < c2.order;
        });
        for (int i = 0; i < today.size() && s; ++i) {
            if (this->history.find(today[i].id) != this->history.end() &&
                this->history[today[i].id] + this->p + 1 > this->cur) {
                // place this check HERE, there're duplicate applications from the same person
                continue;
            }
            this->history[today[i].id] = this->cur, --s;
            cout << today[i].name << ' ' << today[i].id << '\n';
        }
        return true;
    }

    void printConditions() const {
        for (auto &&con : this->conditions) {
            cout << con.name << ' ' << con.id << '\n';
        }
    }
};

int main(int argc, char const *argv[]) {
    MaskDelivery md = MaskDelivery();
    while (md.dailyCheck()) continue;
    md.printConditions();
    return 0;
}
