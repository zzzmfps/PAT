#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
private:
    struct TreeNode
    {
        int data;
        TreeNode *lchild, *rchild;
        TreeNode(int d) : data(d), lchild(nullptr), rchild(nullptr) {}
    };

public:
    void isRedBlackTree()
    {
        int k, n, v;
        cin >> k;
        while (k--) {
            cin >> n >> v;
            TreeNode *root = new TreeNode(v);
            while (--n) {
                cin >> v;
                build(root, v);
            }
            bool isRBTree = true;
            if (root->data < 0 || !checkRule4(root) || !checkRule5(root)) isRBTree = false;
            cout << (isRBTree ? "Yes" : "No") << '\n';
            deleteTree(root);
        }
    }

private:
    void build(TreeNode *&root, int v)
    {
        if (!root) {
            root = new TreeNode(v);
        } else if (abs(v) < abs(root->data)) {
            build(root->lchild, v);
        } else {
            build(root->rchild, v);
        }
    }

    bool checkRule4(TreeNode *root)
    {   // If a node is red, then both its children are black
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            auto x = st.top();
            st.pop();
            if (x->data < 0) {
                if (x->lchild && x->lchild->data < 0) return false;
                if (x->rchild && x->rchild->data < 0) return false;
            }
            if (x->lchild) st.push(x->lchild);
            if (x->rchild) st.push(x->rchild);
        }
        return true;
    }

    bool checkRule5(TreeNode *root)
    {   // All simple paths from the node to leaves contain the same number of black nodes
        vector<int> tmp;
        helper5(root, tmp);
        int x = tmp[0];
        return all_of(tmp.begin(), tmp.end(), [x](int t) { return t == x; });
    }

    void helper5(TreeNode *root, vector<int> &tmp, int n = 0)
    {
        if (!root) {
            tmp.push_back(n);
        } else {
            n += (root->data > 0);
            helper5(root->lchild, tmp, n);
            helper5(root->rchild, tmp, n);
        }
    }

    void deleteTree(TreeNode *root)
    {
        stack<TreeNode *>st;
        st.push(root);
        while (!st.empty()) {
            auto x = st.top();
            st.pop();
            if (x->lchild) st.push(x->lchild);
            if (x->rchild) st.push(x->rchild);
            delete x;
        }
    }
};

int main(void)
{
    Solution s;
    s.isRedBlackTree();
    return 0;
}
