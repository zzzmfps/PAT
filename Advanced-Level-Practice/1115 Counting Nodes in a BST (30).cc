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
        int val;
        Node *lchild, *rchild;
        Node(int v) : val(v), lchild(nullptr), rchild(nullptr) {}
    };
    int n, *count, level;
    Node *head;

  public:
    Solution()
    {
        cin >> n;
        count = new int[n]{1};
        level = 0;

        int v;
        cin >> v;
        head = new Node(v);
        for (int i = 1; i < n; ++i) {
            cin >> v;
            insertBST(head, v, 1);
        }
    }

    ~Solution()
    {
        delete[] count;
        delete[] head;  // need dfs to delete all nodes
    }

    void printResult()
    {
        cout << count[level] << " + " << count[level - 1] << " = " << count[level] + count[level - 1];
    }

  private:
    void insertBST(Node *head, int x, int lv)
    {
        if (x <= head->val) {
            if (!head->lchild) {
                head->lchild = new Node(x);
                ++count[lv];
                level = max(level, lv);
            } else {
                insertBST(head->lchild, x, lv + 1);
            }
        } else {
            if (!head->rchild) {
                head->rchild = new Node(x);
                ++count[lv];
                level = max(level, lv);
            } else {
                insertBST(head->rchild, x, lv + 1);
            }
        }
    }
};

int main(void)
{
    Solution s;
    s.printResult();
    return 0;
}
