#include <algorithm>
#include <iostream>
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
    int n, *pre, *in;
    bool isMirrorImage, isBst = true;
    Node *root;

  public:
    Solution()
    {
        cin >> n;
        pre = new int[n];
        for (int i = 0; i < n; ++i) cin >> pre[i];
        isMirrorImage = (pre[0] <= pre[1]);
        in = new int[n];
        if (isMirrorImage) {
            partial_sort_copy(pre, pre + n, in, in + n, greater<int>());
        } else {
            partial_sort_copy(pre, pre + n, in, in + n);
        }
    }

    void checkAndPrint()
    {
        root = createBst(0, n - 1, 0, n - 1);
        if (isBst) {
            cout << "YES\n";
            getPostOrderSequence(root);
        } else {
            cout << "NO\n";
        }
    }

  private:
    void check(int pl, int pr, int il, int ir)
    {
        int length = pr - pl + 1, *tmp = new int[length];
        if (isMirrorImage) {
            partial_sort_copy(pre + pl, pre + pr + 1, tmp, tmp + length, greater<int>());
        } else {
            partial_sort_copy(pre + pl, pre + pr + 1, tmp, tmp + length);
        }
        for (int i = 0; i < length; ++i) {
            if (tmp[i] != in[il + i]) {
                isBst = false;
                return;
            }
        }
    }

    Node *createBst(int pl, int pr, int il, int ir)
    {
        if (pl > pr || !isBst) return nullptr;
        check(pl, pr, il, ir);
        if (!isBst) return nullptr;
        Node *node = new Node(pre[pl]);
        int idx;
        if (isMirrorImage) {
            for (idx = ir; idx >= il; --idx)
                if (in[idx] == node->data) break;
        } else {
            for (idx = il; idx <= ir; ++idx)
                if (in[idx] == node->data) break;
        }
        int k = idx - il;
        node->lchild = createBst(pl + 1, pl + k, il, idx - 1);
        node->rchild = createBst(pl + k + 1, pr, idx + 1, ir);
        return node;
    }

    void getPostOrderSequence(Node *node)
    {
        if (!node) return;
        getPostOrderSequence(node->lchild);
        getPostOrderSequence(node->rchild);
        cout << node->data << (node == root ? "\n" : " ");
    }
};

int main(void)
{
    Solution s;
    s.checkAndPrint();
    return 0;
}
