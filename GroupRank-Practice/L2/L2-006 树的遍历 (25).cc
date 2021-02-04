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
    TreeNode *head = nullptr;
    vector<int> postorder;
    vector<int> inorder;

public:
    Solution()
    {
        int n;
        cin >> n;
        postorder.resize(n);
        for (int i = 0; i < n; ++i) cin >> postorder[i];
        inorder.resize(n);
        for (int i = 0; i < n; ++i) cin >> inorder[i];
        build(head, 0, n - 1, 0, n - 1);
    }

    void printLevelorder()
    { // simple level order traversal
        queue<TreeNode *> q;
        q.push(head);
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            cout << (tmp == head ? "" : " ") << tmp->val;
            if (tmp->lchild) q.push(tmp->lchild);
            if (tmp->rchild) q.push(tmp->rchild);
            q.pop();
        }
    }

private:
    void build(TreeNode *&node, int pl, int pr, int il, int ir)
    { // root node is the last element of postorder, and the very element
      // divides inorder sequence into two parts: left and right sub-trees
        if (pl > pr) return;
        int val = postorder[pr], delim = il;
        node = new TreeNode(val);
        while (inorder[delim] != val) ++delim;
        build(node->lchild, pl, pl + delim - il - 1, il, delim - 1);
        build(node->rchild, pl + delim - il, pr - 1, delim + 1, ir);
    }
};

int main(void)
{
    Solution s;
    s.printLevelorder();
    return 0;
}
