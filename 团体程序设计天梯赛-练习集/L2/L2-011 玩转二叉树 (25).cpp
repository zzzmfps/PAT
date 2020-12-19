#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
private:
    struct TreeNode {
        int val;
        TreeNode *lchild, *rchild;
        TreeNode(int v) : val(v), lchild(nullptr), rchild(nullptr) {}
    };
    TreeNode *root = nullptr;
    vector<int> inorder, preorder;

public:
    Solution()
    {
        int n;
        cin >> n;
        inorder.resize(n), preorder.resize(n);
        for (int i = 0; i < n; ++i) cin >> inorder[i];
        for (int i = 0; i < n; ++i) cin >> preorder[i];
        root = build(0, n - 1, 0, n - 1);
    }

    void getLevelOrder()
    {
        queue<TreeNode *> q;
        q.push(root);
        while (true) {
            TreeNode *tmp = q.front();
            cout << tmp->val;
            if (tmp->lchild) q.push(tmp->lchild);
            if (tmp->rchild) q.push(tmp->rchild);
            q.pop();
            if (q.empty()) break;
            cout << ' ';
        }
    }

private:
    TreeNode *build(int il, int ir, int pl, int pr)
    {
        if (il > ir) return nullptr;
        TreeNode *node = new TreeNode(preorder[pl]);
        int split = il;
        while (inorder[split] != preorder[pl]) ++split;
        node->lchild = build(split + 1, ir, pr - ir + split + 1, pr); // reverse
        node->rchild = build(il, split - 1, pl + 1, pl + split - il); // reverse
        return node;
    }
};

int main(void)
{
    Solution s;
    s.getLevelOrder();
    return 0;
}
