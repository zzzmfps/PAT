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
        int data, height;
        Node *lchild, *rchild;
        Node(int d, int h = 1) : data(d), height(h), lchild(nullptr), rchild(nullptr) {}
    };
    int n;
    Node *avl = nullptr;

  public:
    Solution()
    {
        cin >> n;
        for (int i = 0, tmp; i < n; ++i) {
            cin >> tmp;
            insert(avl, tmp);
        }
    }

    int getRootData() { return avl->data; }

  private:
    void insert(Node *&root, int val)
    {
        if (!root) {
            root = new Node(val);
            return;
        }
        if (val < root->data) {
            insert(root->lchild, val);
            updateHeight(root);
            if (getBalanceFactor(root) == 2) {
                if (getBalanceFactor(root->lchild) == -1) leftRotation(root->lchild);
                rightRotation(root);
            }
        } else {
            insert(root->rchild, val);
            updateHeight(root);
            if (getBalanceFactor(root) == -2) {
                if (getBalanceFactor(root->rchild) == 1) rightRotation(root->rchild);
                leftRotation(root);
            }
        }
    }

    void rightRotation(Node *&root)
    {
        Node *tmp = root->lchild;
        root->lchild = tmp->rchild;
        tmp->rchild = root;
        updateHeight(root);
        updateHeight(tmp);
        root = tmp;
    }

    void leftRotation(Node *&root)
    {
        Node *tmp = root->rchild;
        root->rchild = tmp->lchild;
        tmp->lchild = root;
        updateHeight(root);
        updateHeight(tmp);
        root = tmp;
    }

    void updateHeight(Node *root) { root->height = 1 + max(getHeight(root->lchild), getHeight(root->rchild)); }

    int getHeight(Node *root) { return (root ? root->height : 0); }

    int getBalanceFactor(Node *root) { return getHeight(root->lchild) - getHeight(root->rchild); }
};

int main(void)
{
    Solution s;
    cout << s.getRootData();
    return 0;
}
