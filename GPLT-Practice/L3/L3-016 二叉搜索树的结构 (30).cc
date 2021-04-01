#include <bits/stdc++.h>

struct Node {
    int value, height;
    Node *parent;
    Node *lchild = nullptr, *rchild = nullptr;
    Node(int v, int h, Node *p) : value(v), height(h), parent(p) {}
};

class BstStructure {
private:
    Node *root = nullptr;

public:
    BstStructure() {
        int n;
        std::cin >> n;
        for (int i = 0, v; i < n; ++i) {
            std::cin >> v;
            this->insert(v);
        }
    }

    void process() {
        int m;
        (std::cin >> m).get();
        while (m--) {
            bool flag = false;

            std::string in;
            std::getline(std::cin, in);

            size_t idx1 = in.find(' ');
            int a = std::stoi(in.substr(0, idx1));
            auto n1 = this->search(a);

            if ('t' == in.back()) {
                flag = (n1 == this->root);
            } else if (isalpha(in.back())) {
                size_t idx2 = in.find(' ', idx1 + 6);
                int b = std::stoi(in.substr(idx1 + 5, idx2 - idx1 - 5));
                auto n2 = this->search(b);
                switch (in.back()) {
                    case 's': flag = (n1 && n2 && n1->parent == n2->parent); break;
                    case 'l': flag = (n1 && n2 && n1->height == n2->height); break;
                }
            } else {
                size_t idx2 = in.rfind(' ');
                int b = std::stoi(in.substr(idx2 + 1));
                auto n2 = this->search(b);
                switch (in[idx2 - 11]) {
                    case 'e': flag = (n1 && n2 && n1 == n2->parent); break;
                    case 'f': flag = (n1 && n2 && n1 == n2->lchild); break;
                    case 'h': flag = (n1 && n2 && n1 == n2->rchild); break;
                }
            }

            std::cout << (flag ? "Yes" : "No") << '\n';
        }
    }

private:
    void insert(int val) { // meets segment fault if use recursion
        if (!this->root) {
            this->root = new Node(val, 1, nullptr);
            return;
        }
        Node *node = root;
        for (int h = 2;; ++h) {
            if (val < node->value) {
                if (node->lchild) {
                    node = node->lchild;
                } else {
                    node->lchild = new Node(val, h, node);
                    break;
                }
            } else {
                if (node->rchild) {
                    node = node->rchild;
                } else {
                    node->rchild = new Node(val, h, node);
                    break;
                }
            }
        }
    }

    Node *search(int val) {
        Node *node = root;
        while (node) {
            if (val == node->value) break;
            node = (val < node->value ? node->lchild : node->rchild);
        }
        return node;
    }
};

int main(void) {
    BstStructure bs;
    bs.process();
    return 0;
}
