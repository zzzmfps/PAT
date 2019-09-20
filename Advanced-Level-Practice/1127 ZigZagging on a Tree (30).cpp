#include <algorithm>
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
    int n;
    vector<int> inorder, postorder;

public:
    Solution()
    {
        cin >> n;
        inorder.resize(n), postorder.resize(n);
        for (int i = 0; i < n; ++i) cin >> inorder[i];
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

    void zigZag()
    {
        root = build(0, n - 1, 0, n - 1);
        cout << root->val;
        queue<TreeNode *> q;
        if (root->lchild) q.push(root->lchild);
        if (root->rchild) q.push(root->rchild);
        bool rev = false;
        while (!q.empty()) {
            vector<int> curLevel;
            for (int i = q.size(); i > 0; --i) {
                auto tmp = q.front();
                curLevel.push_back(tmp->val);
                if (tmp->lchild) q.push(tmp->lchild);
                if (tmp->rchild) q.push(tmp->rchild);
                q.pop();
            }
            if (rev) reverse(curLevel.begin(), curLevel.end());
            rev ^= true;
            for (auto v : curLevel) cout << ' ' << v;
        }
    }

private:
    TreeNode *build(int il, int ir, int pl, int pr)
    {
        if (il > ir) return nullptr;
        int val = postorder[pr];
        int idx = il;
        while (inorder[idx] != val) ++idx;
        TreeNode *head = new TreeNode(val);
        head->lchild = build(il, idx - 1, pl, pl + idx - 1 - il);
        head->rchild = build(idx + 1, ir, pl + idx - il, pr - 1);
        return head;
    }
};

int main(void)
{
    Solution s;
    s.zigZag();
    return 0;
}
