#include <iostream>
#include <stack>
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
    Node *root;

  public:
    Solution()
    {
        Node *head = new Node(0), *last = head;

        string op;
        int data;
        bool isLastPush = true;
        stack<Node *> st;
        
        cin >> n;
        for (int i = 2 * n; i > 0; --i) {
            cin >> op;
            if (op == "Push") {
                cin >> data;
                auto &tmp = isLastPush ? last->lchild : last->rchild;
                tmp = new Node(data);
                st.push(tmp);
                last = tmp, isLastPush = true;
            } else {
                last = st.top(), isLastPush = false;
                st.pop();
            }
        }
        root = head->lchild;
        delete head;
    }

    void printPostOrderSequence() { helper(root); }

  private:
    void helper(Node *node)
    {
        if (!node) return;
        helper(node->lchild);
        helper(node->rchild);
        cout << node->data;
        if (node->data != root->data) cout << ' ';
    }
};

int main(void)
{
    Solution s;
    s.printPostOrderSequence();
    return 0;
}
