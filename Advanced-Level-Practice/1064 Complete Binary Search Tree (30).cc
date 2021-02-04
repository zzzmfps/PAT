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
        Node *lchild, *rchild;
        Node(int d) : data(d), lchild(nullptr), rchild(nullptr) {}
    };
    int n, *seq;
    int ret[11] = {0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023};

  public:
    Solution()
    {
        cin >> n;
        seq = new int[n];
        for (int i = 0; i < n; ++i) cin >> seq[i];
        sort(seq, seq + n);
    }

    void getLevelOrderSequence()
    {
        Node *root = create(0, n - 1);
        queue<Node *> tmp;
        tmp.push(root);
        while (!tmp.empty()) {
            auto &node = tmp.front();
            tmp.pop();
            cout << (node->data == root->data ? "" : " ") << node->data;
            if (node->lchild) tmp.push(node->lchild);
            if (node->rchild) tmp.push(node->rchild);
        }
    }

  private:
    Node *create(int beg, int end)
    {
        if (beg > end) return nullptr;
        int count = end - beg + 1;
        int num1 = getMaxExp(count), num2 = count - num1, num3 = (num1 + 1) >> 1;
        int left = min(num2, num3), right = num2 - left;
        int idx = (beg + left + end - right) / 2;
        Node *root = new Node(seq[idx]);
        root->lchild = create(beg, idx - 1);
        root->rchild = create(idx + 1, end);
        return root;
    }

    int getMaxExp(int num)
    {
        for (int i = 1; i < 12; ++i)
            if (ret[i] > num) return ret[i - 1];
        return 1023;
    }
};

int main(void)
{
    Solution s;
    s.getLevelOrderSequence();
    return 0;
}
