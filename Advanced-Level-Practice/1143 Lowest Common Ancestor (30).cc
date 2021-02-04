#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    void lowestCommonAncestor()
    {
        int query, node;
        cin >> query >> node;
        vector<int> preorder(node);
        for (int i = 0; i < node; ++i) cin >> preorder[i];
        unordered_set<int> nodes(preorder.begin(), preorder.end());

        while (query--) {
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
                int val;
                for (int i = 0; i < node; ++i) {
                    val = preorder[i];
                    if (val == a || val == b || val > a && val < b || val < a && val > b) break;
                }
                if (val == b) swap(a, b);
                if (val == a) {
                    cout << a << " is an ancestor of " << b << ".\n";
                } else {
                    cout << "LCA of " << a << " and " << b << " is " << val << ".\n";
                }
            }
        }
    }
};

int main(void)
{
    Solution s;
    s.lowestCommonAncestor();
    return 0;
}
