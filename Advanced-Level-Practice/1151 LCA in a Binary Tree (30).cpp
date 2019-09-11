#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    void binaryTreeLCA()
    {
        int query, node;
        cin >> query >> node;
        vector<int> inorder(node);
        vector<int> preorder(node);
        for (int i = 0; i < node; ++i) cin >> inorder[i];
        for (int i = 0; i < node; ++i) cin >> preorder[i];
        unordered_set<int> nodes(inorder.begin(), inorder.end());

        while (query--) {
            // check if a, b is existed
            int a, b;
            cin >> a >> b;
            bool miss1 = false, miss2 = false;
            if (nodes.find(a) == nodes.end()) miss1 = true;
            if (nodes.find(b) == nodes.end()) miss2 = true;
            if (miss1 || miss2) {
                cout << "ERROR: ";
                if (miss1 && !miss2) {
                    cout << a << " is";
                } else if (!miss1 && miss2) {
                    cout << b << " is";
                } else {
                    cout << a << " and " << b << " are";
                }
                cout << " not found.\n";
            } else {
                /*
                inorder sequence:  ...a...c...b... or ...a...b...
                                   LCA must be (between/equal to) a, b
                preorder sequence: ...c...a...b... or ...a...b...
                                   LCA must be in front(left) of a and b,
                                            or equal to a if a is in left of b else b
                */
                int i = 0;
                while (inorder[i] != a && inorder[i] != b) ++i;
                int j = i + 1;
                while (inorder[j] != a && inorder[j] != b) ++j;
                int k = 0;
                while (preorder[k] != a && preorder[k] != b) ++k;
                unordered_set<int> tmp(inorder.begin() + i + 1, inorder.begin() + j);
                bool flag = true;
                if (!tmp.empty()) {
                    for (int l = 0; l < k; ++l) {
                        if (tmp.find(preorder[l]) != tmp.end()) {
                            cout << "LCA of " << a << " and " << b << " is " << preorder[l] << ".\n";
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag) cout << preorder[k] << " is an ancestor of " << (preorder[k] == a ? b : a) << ".\n";
            }
        }
    }
};

int main(void)
{
    Solution s;
    s.binaryTreeLCA();
    return 0;
}
