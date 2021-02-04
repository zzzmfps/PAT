#include <algorithm>
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
        int lchild, rchild;
        Node(int d = 0) : data(d), lchild(-1), rchild(-1) {}
    };
    int n, *seq, root = 0;
    Node *bst;

  public:
    Solution()
    {
        cin >> n;
        bst = new Node[n];
        for (int i = 0; i < n; ++i) cin >> bst[i].lchild >> bst[i].rchild;
        seq = new int[n];
        for (int i = 0; i < n; ++i) cin >> seq[i];
        sort(seq, seq + n);
    }

    void getLevelOrderSequence()
    {
        int i = 0;
        completeBstWithInOrderTraversal(root, i);
        queue<int> tmp;
        tmp.push(root);
        while (!tmp.empty()) {
            int x = tmp.front();
            tmp.pop();
            cout << (bst[x].data == bst[root].data ? "" : " ") << bst[x].data;
            if (bst[x].lchild != -1) tmp.push(bst[x].lchild);
            if (bst[x].rchild != -1) tmp.push(bst[x].rchild);
        }
    }

  private:
    void completeBstWithInOrderTraversal(int x, int &i)
    {
        if (x == -1) return;
        completeBstWithInOrderTraversal(bst[x].lchild, i);
        bst[x].data = seq[i++];
        completeBstWithInOrderTraversal(bst[x].rchild, i);
    }
};

int main(void)
{
    Solution s;
    s.getLevelOrderSequence();
    return 0;
}
