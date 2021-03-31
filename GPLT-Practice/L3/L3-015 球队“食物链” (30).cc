#include <bits/stdc++.h>

template <typename T1>
using Vector = std::vector<T1>;
template <typename T2>
using HashSets = Vector<std::set<T2>>;

class FoodChain {
private:
    size_t n;
    HashSets<size_t> record;
    Vector<size_t> result;

public:
    Vector<size_t> process() {
        this->init();
        this->dfs(new bool[1 + this->n]{}, 0);
        return this->result;
    }

private:
    void init() {
        (std::cin >> this->n).get();
        this->record = HashSets<size_t>(1 + this->n);
        this->record[0] = {1};
        for (size_t i = 1; i <= this->n; ++i) {
            for (size_t j = 1; j <= this->n; ++j) {
                switch (std::cin.get()) {
                    case 'W': this->record[i].insert(j); break;
                    case 'L': this->record[j].insert(i); break;
                }
            }
            std::cin.get();
        }
        this->result.clear();
    }

    bool dfs(bool *visited, int x) {
        if (this->result.size() == this->n) {
            if (this->record[x].find(this->result[0]) == this->record[x].end()) return false;
            delete[] visited;
            return true;
        }

        bool possible = false;
        for (size_t i = 2; i <= this->n; ++i) {
            if (visited[i]) continue;
            if (this->record[i].find(1) != this->record[i].end()) {
                possible = true;
                break;
            }
        }
        if (!possible) return false;

        for (auto &&_next : this->record[x]) {
            if (visited[_next]) continue;
            visited[_next] = true;
            this->result.push_back(_next);
            if (this->dfs(visited, _next)) return true;
            this->result.pop_back();
            visited[_next] = false;
        }
        return false;
    }
};

int main(void) {
    FoodChain fc;
    auto res = fc.process();
    if (res.empty()) {
        std::cout << "No Solution";
    } else {
        std::cout << res[0];
        for (size_t i = 1; i < res.size(); ++i) std::cout << ' ' << res[i];
    }
    return 0;
}
