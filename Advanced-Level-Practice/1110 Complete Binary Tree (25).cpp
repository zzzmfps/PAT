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
        int lchild, rchild;
        Node(int l = -1, int r = -1) : lchild(l), rchild(r) {}
    };
    int n, root = 0, real = 1;
    Node *tree;

  public:
    Solution()
    {
        (cin >> n).get();

        tree = new Node[n];
        bool *isLeaves = new bool[n]{};
        for (int i = 0; i < n; ++i) {
            if (cin.peek() != '-') {
                cin >> tree[i].lchild;
                isLeaves[tree[i].lchild] = true;
            }
            cin.ignore(2, ' ');
            if (cin.peek() != '-') {
                cin >> tree[i].rchild;
                isLeaves[tree[i].rchild] = true;
            }
            cin.ignore(2, '\n');
        }

        while (isLeaves[root]) ++root;
        delete[] isLeaves;
    }

    void checkBiT()
    {  // bfs
        queue<int> tmp;
        tmp.push(root);
        while (true) {
            auto &x = tree[tmp.front()];
            tmp.pop();
            if (x.lchild >= 0 && x.rchild >= 0) {
                tmp.push(x.lchild);
                tmp.push(x.rchild);
                real += 2;
            } else {
                if (x.lchild >= 0) {
                    tmp.push(x.lchild);
                    real += 1;
                }
                if (real != n) {
                    cout << "NO " << root;
                } else {
                    cout << "YES " << tmp.back();
                }
                break;
            }
        }
    }
};

int main(void)
{
    Solution s;
    s.checkBiT();
    return 0;
}
