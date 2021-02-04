#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
private:
    struct TreeNode
    {
        int val;
        TreeNode *lchild, *rchild;
        TreeNode(int v) : val(v), lchild(nullptr), rchild(nullptr) {}
    } *root = nullptr;
    bool isUnique = true, isFirst=true;
    int n;
    vector<int> preorder, postorder;

public:
    Solution()
    {
        cin >> n;
        preorder.resize(n), postorder.resize(n);
        for (int i = 0; i < n; ++i) cin >> preorder[i];
        for (int i = 0; i < n; ++i) cin >> postorder[i];
    }

    ~Solution()
    {
        queue<TreeNode *>q;
        q.push(root);
        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();
            if (tmp->lchild) q.push(tmp->lchild);
            if (tmp->rchild) q.push(tmp->rchild);
            delete[] tmp;
        }
    }

    void buildBTFromPreNPost()
    {
        root = build(0, n - 1, 0, n - 1);
        cout << (isUnique ? "Yes" : "No") << '\n';
        inorderTraverse(root);
        cout<< '\n';  // an extra newline needed, or format error and gets 0 point
    }

private:
    TreeNode *build(int prel, int prer, int postl, int postr)
    {
        // the key idea is that a tree is unique only when the degrees of its nodes are all 0 or 2
        if (prel > prer) return nullptr;
        TreeNode *node = new TreeNode(preorder[prel]);  // head node: preorder[prel] and postorder[postr]
        if (prel + 1 > prer) return node; // out of index, or the node must have at least one child
        int val = preorder[prel + 1]; // take it as left child by default, then check right
        int idx = postl;
        while (postorder[idx] != val) ++idx;  // divide remaining array into left and right child arrays
        if (idx == postr - 1) isUnique = false; // has left child but no right child, thus not unique
        node->lchild = build(prel + 1, prel + idx - postl + 1, postl, idx);
        node->rchild = build(prel + idx - postl + 2, prer, idx + 1, postr - 1);
        return node;
    }

    void inorderTraverse(TreeNode *node)
    {
        if (!node) return;
        inorderTraverse(node->lchild);
        cout << (isFirst ? "" : " ") << node->val;
        isFirst = false;
        inorderTraverse(node->rchild);
    }
};

int main(void)
{
    Solution s;
    s.buildBTFromPreNPost();
    return 0;
}
