#include <bits/stdc++.h>

class Avl {
public:
    struct Node {
        int data, height;
        Node *left, *right;
        Node(int d, int h = 1) : data(d), height(h), left(nullptr), right(nullptr) {}
    };

    static void insert(Node *&root, int val) {
        if (!root) {
            root = new Node(val);
        } else if (val < root->data) {
            insert(root->left, val);
            updateHeight(root);
            if (getBalanceFactor(root) == 2) {
                if (getBalanceFactor(root->left) == -1) leftRotate(root->left);
                rightRotate(root);
            }
        } else {
            insert(root->right, val);
            updateHeight(root);
            if (getBalanceFactor(root) == -2) {
                if (getBalanceFactor(root->right) == 1) rightRotate(root->right);
                leftRotate(root);
            }
        }
    }

private:
    static int getHeight(Node *root) {
        return (root ? root->height : 0);
    }

    static int getBalanceFactor(Node *root) {
        return getHeight(root->left) - getHeight(root->right);
    }

    static void updateHeight(Node *root) {
        root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
    }

    static void rightRotate(Node *&root) {
        Node *tmp = root->left;
        root->left = tmp->right;
        tmp->right = root;
        updateHeight(root);
        updateHeight(tmp);
        root = tmp;
    }

    static void leftRotate(Node *&root) {
        Node *tmp = root->right;
        root->right = tmp->left;
        tmp->left = root;
        updateHeight(root);
        updateHeight(tmp);
        root = tmp;
    }
};

class Solution {
private:
    Avl::Node *avl = nullptr;

public:
    Solution() {
        int n;
        std::cin >> n;
        for (int i = 0, v; i < n; ++i) {
            std::cin >> v;
            Avl::insert(avl, v);
        }
    }

    void isCompleteAvlTree() {
        std::queue<Avl::Node *> q;
        q.push(avl);
        bool isComplete = true, flag = false;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                auto x = q.front();
                std::cout << (x == avl ? "" : " ") << x->data;
                if (x->left) {
                    if (flag) isComplete = false;
                    q.push(x->left);
                } else {
                    flag = true;
                }
                if (x->right) {
                    if (flag) isComplete = false;
                    q.push(x->right);
                } else {
                    flag = true;
                }
                q.pop();
            }
        }
        std::cout << '\n' << (isComplete ? "YES" : "NO");
    }
};

int main(void) {
    Solution s;
    s.isCompleteAvlTree();
    return 0;
}
