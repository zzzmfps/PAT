#include <iomanip>
#include <iostream>
#include <map>
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
    int n;
    vector<int> preorder;
    bool isMirror; // left child is larger than right one if true
    TreeNode *head;

public:
    Solution()
    {
        cin >> n;
        preorder.resize(n);
        for (int i = 0; i < n; ++i) cin >> preorder[i];
        isMirror = (preorder.size() > 1 && preorder[0] < preorder[1]);
    }

    void isBST()
    {
        buildBST();
        int idx = 0;
        if (checkPreorder(head, idx)) {
            cout << "YES\n";
            printPostorder(head);
        } else {
            cout << "NO\n";
        }
    }

private:
    void buildBST()
    { // preorder of BST is exactly the order of building of BST
        head = new TreeNode(preorder[0]);
        for (int i = 1, size = preorder.size(); i < size; ++i) {
            TreeNode *tmp = head;
            while (true) {
                if (isMirror && preorder[i] >= tmp->val || !isMirror && preorder[i] < tmp->val) {
                    if (!tmp->lchild) {
                        tmp->lchild = new TreeNode(preorder[i]);
                        break;
                    }
                    tmp = tmp->lchild;
                } else {
                    if (!tmp->rchild) {
                        tmp->rchild = new TreeNode(preorder[i]);
                        break;
                    }
                    tmp = tmp->rchild;
                }
            }
        }
    }

    bool checkPreorder(TreeNode *node, int &i)
    {
        if (!node) return true;
        if (node->val != preorder[i++]) return false; // check by preorder
        return checkPreorder(node->lchild, i) && checkPreorder(node->rchild, i);
    }

    void printPostorder(TreeNode *node)
    {
        if (!node) return;
        printPostorder(node->lchild);
        printPostorder(node->rchild);
        cout << node->val << (node == head ? "\n" : " ");
    }
};

int main(void)
{
    Solution s;
    s.isBST();
    return 0;
}
