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
    Node *root, *rd;

  public:
    Solution()
    {
        cin >> n;
        bool *isNotRoot = new bool[n]{};
        Node **list = new Node *[n] {};
        for (int i = 0; i < n; ++i) list[i] = new Node(i);

        char left, right;
        for (int i = 0; i < n; ++i) {
            cin >> left >> right;
            list[i]->lchild = (left == '-' ? nullptr : (isNotRoot[left - '0'] = true, list[left - '0']));
            list[i]->rchild = (right == '-' ? nullptr : (isNotRoot[right - '0'] = true, list[right - '0']));
        }

        for (int i = 0; i < n; ++i)
            if (!isNotRoot[i]) {
                rd = root = list[i];
                break;
            }
        while (rd->lchild) rd = rd->lchild;
        delete[] isNotRoot;
    }

    void traverse()
    {
        invertBT(root);
        printLevelOrderSequence();
        printInOrderSequence(root);
    }

  private:
    Node *invertBT(Node *node)
    {
        if (!node) return node;
        swap(node->lchild, node->rchild);
        invertBT(node->rchild);
        invertBT(node->lchild);
    }

    void printLevelOrderSequence()
    {
        queue<Node *> tmp;
        tmp.push(root);
        while (true) {
            auto &node = tmp.front();
            tmp.pop();
            cout << node->data;
            if (node->lchild) tmp.push(node->lchild);
            if (node->rchild) tmp.push(node->rchild);
            if (tmp.empty()) {
                break;
            } else {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    void printInOrderSequence(Node *node)
    {
        if (!node) return;
        printInOrderSequence(node->lchild);
        cout << node->data << (node->data == rd->data ? "" : " ");
        printInOrderSequence(node->rchild);
    }
};

int main(void)
{
    Solution s;
    s.traverse();
    return 0;
}
