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
        for (int i = 1; i < level.size(); ++i) cout << (1 == i ? "" : " ") << level[i];
    }

private:
    void dfs(int index) {
        if (1 + index > post.size()) return;
        dfs(index << 1);
        dfs(index << 1 | 1);
        level[index] = post[++count];
    }
};

int main(int argc, char const *argv[]) {
    ConstructCBT cbt = ConstructCBT();
    cbt.printByLevelOrder();
    return 0;
}
