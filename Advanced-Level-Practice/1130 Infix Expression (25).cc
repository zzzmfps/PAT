#include <iostream>
#include <string>
using namespace std;

class Solution
{
private:
    struct ArrayNode
    {
        string data;
        int lchild, rchild;
    } *arr;
    const string op = "+-*/%^";

public:
    ~Solution() { delete[] arr; }

    void infixExpression()
    {
        int n;
        cin >> n;
        arr = new ArrayNode[n + 1];
        bool *isNotRoot = new bool[n + 1] {};
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i].data >> arr[i].lchild >> arr[i].rchild;
            if (arr[i].lchild > 0) isNotRoot[arr[i].lchild] = true;
            if (arr[i].rchild > 0) isNotRoot[arr[i].rchild] = true;
        }
        int root = 1;
        while (isNotRoot[root]) ++root;
        delete[] isNotRoot;
        inorderTraverse(root);
    }

private:
    void inorderTraverse(int node)
    {
        if (node == -1) return;
        if (arr[node].lchild > 0) {
            bool isOp = (op.find(arr[arr[node].lchild].data) != string::npos);
            if (isOp) cout << '(';
            inorderTraverse(arr[node].lchild);
            if (isOp) cout << ')';
        }
        cout << arr[node].data;
        if (arr[node].rchild > 0) {
            bool isOp = (op.find(arr[arr[node].rchild].data) != string::npos);
            if (isOp) cout << '(';
            inorderTraverse(arr[node].rchild);
            if (isOp) cout << ')';
        }
    }
};

int main(void)
{
    Solution s;
    s.infixExpression();
    return 0;
}
