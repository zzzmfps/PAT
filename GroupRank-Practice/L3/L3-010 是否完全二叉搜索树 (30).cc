#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *lchild, *rchild;
    TreeNode(int v) : val(v), lchild(nullptr), rchild(nullptr) {}
};

class BST {
private:
    int n;
    TreeNode *root = nullptr;
    bool complete = true;

public:
    BST() {
        cin >> this->n;
        for (int i = 0, val; i < this->n; ++i) {
            cin >> val;
            int index = this->addNode(this->root, val);
            this->complete &= (index <= this->n);
        }
    }

    void process() {
        queue<TreeNode *> q;
        q.push(this->root);
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->lchild) q.push(cur->lchild);
            if (cur->rchild) q.push(cur->rchild);
            cout << cur->val << (q.empty() ? '\n' : ' ');
        }
        cout << (this->complete ? "YES" : "NO");
    }

private:
    int addNode(TreeNode *&node, int val, int index = 1) {
        if (!node) {
            node = new TreeNode(val);
        } else if (val > node->val) {
            index = this->addNode(node->lchild, val, 2 * index);
        } else {
            index = this->addNode(node->rchild, val, 2 * index + 1);
        }
        return index;
    }
};

int main(void) {
    BST bst;
    bst.process();
    return 0;
}
