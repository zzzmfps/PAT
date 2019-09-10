#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void postorderTraversal()
    {
        int n;
        cin >> n;
        vector<int> preorder(n), inorder(n);
        for (int i = 0; i < n; ++i) cin >> preorder[i];
        for (int i = 0; i < n; ++i) cin >> inorder[i];
        auto head = build(preorder, inorder, 0, n - 1, 0, n - 1);
        while (head->left || head->right) head = (head->left ? head->left : head->right);
        cout << head->val;
    }

private:
    TreeNode *build(const vector<int> &pre, const vector<int> &in, int pl, int pr, int il, int ir)
    {
        if (pl > pr) return nullptr;
        int nodeval = pre[pl];
        TreeNode *head = new TreeNode(nodeval);
        if (pl < pr) {
            int idx = il;
            while (in[idx] != nodeval) ++idx;
            head->left = build(pre, in, pl + 1, idx + pl - il, il, idx - 1);
            head->right = build(pre, in, idx + pl - il + 1, pr, idx + 1, ir);
        }
        return head;
    }
};

int main(void)
{
    Solution s;
    s.postorderTraversal();
    return 0;
}
