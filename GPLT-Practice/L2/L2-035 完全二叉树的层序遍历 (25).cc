#include <bits/stdc++.h>
using namespace std;

class ConstructCBT {
private:
    int count = 0;
    vector<int> post, level;

public:
    ConstructCBT() {
        int n;
        cin >> n;
        this->post.resize(1 + n);
        this->level.resize(1 + n);
        for (int i = 1; i <= n; ++i) cin >> this->post[i];
        this->dfs(1);
    }

    void printByLevelOrder() {
        copy(this->level.begin() + 1, this->level.end(), ostream_iterator<int>(cout, " "));
    }

private:
    void dfs(int index) {
        if (1 + index > this->post.size()) return;
        dfs(index << 1);
        dfs(index << 1 | 1);
        this->level[index] = this->post[++count];
    }
};

int main(int argc, char const *argv[]) {
    ConstructCBT cbt = ConstructCBT();
    cbt.printByLevelOrder();
    return 0;
}
