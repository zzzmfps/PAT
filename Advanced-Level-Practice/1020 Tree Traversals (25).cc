#include <iostream>
#include <queue>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  private:
    struct Node {
        int data;
        Node *lchild, *rchild;
        Node(int d) : data(d), lchild(nullptr), rchild(nullptr) {}
    };
    int n;
    int *post, *inorder;

  public:
    Solution()
    {
        cin >> n;
        post = new int[n];
        for (int i = 0; i < n; ++i) cin >> post[i];
        inorder = new int[n];
        for (int i = 0; i < n; ++i) cin >> inorder[i];
    }

    void printLevelOrderSequence()
    {
        auto root = create(0, n - 1, 0, n - 1);
        queue<Node *> tmp;
        tmp.push(root);
        while (true) {
            auto node = tmp.front();
            tmp.pop();
            if (node->lchild) tmp.push(node->lchild);
            if (node->rchild) tmp.push(node->rchild);
            cout << node->data;
            if (tmp.empty()) {
                break;
            } else {
                cout << ' ';
            }
        }
    }

  private:
    Node *create(int pl, int pr, int il, int ir)
    {
        if (pl > pr) return nullptr;
        Node *root = new Node(post[pr]);
        int idx;
        for (idx = il; idx <= ir; ++idx)
            if (inorder[idx] == root->data) break;
        int k = idx - il;

        root->lchild = create(pl, pl + k - 1, il, idx - 1);
        root->rchild = create(pl + k, pr - 1, idx + 1, ir);
        return root;
    }
};

int main(void)
{
    Solution s;
    s.printLevelOrderSequence();
    return 0;
}
