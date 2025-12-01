#include <iostream>
using namespace std;

struct Node {
    int val;
    int height;
    Node* left;
    Node* right;

    Node(int v) {
        val = v;
        height = 1;
        left = right = nullptr;
    }
};

class AVL {
private:
    Node* root = nullptr;

    int h(Node* n) {
        return n ? n->height : 0;
    }

    int balance(Node* n) {
        return n ? h(n->left) - h(n->right) : 0;
    }

    Node* rotateRight(Node* y) { // LL
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(h(y->left), h(y->right)) + 1;
        x->height = max(h(x->left), h(x->right)) + 1;

        return x;
    }

    Node* rotateLeft(Node* x) { // RR
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(h(x->left), h(x->right)) + 1;
        y->height = max(h(y->left), h(y->right)) + 1;

        return y;
    }

    Node* insert(Node* n, int v) {
        if (!n) return new Node(v);

        if (v < n->val)
            n->left = insert(n->left, v);
        else if (v > n->val)
            n->right = insert(n->right, v);
        else
            return n;

        n->height = 1 + max(h(n->left), h(n->right));

        int b = balance(n);

        // LL
        if (b > 1 && v < n->left->val)
            return rotateRight(n);

        // RR
        if (b < -1 && v > n->right->val)
            return rotateLeft(n);

        // LR
        if (b > 1 && v > n->left->val) {
            n->left = rotateLeft(n->left);
            return rotateRight(n);
        }

        // RL
        if (b < -1 && v < n->right->val) {
            n->right = rotateRight(n->right);
            return rotateLeft(n);
        }

        return n;
    }

    void inorder(Node* n) {
        if (!n) return;
        inorder(n->left);
        cout << n->val << " ";
        inorder(n->right);
    }

public:
    void insert(int v) {
        root = insert(root, v);
    }

    void inorder() {
        inorder(root);
        cout << "\n";
    }
};

int main() {
    AVL t;
    t.insert(30);
    t.insert(20);
    t.insert(10); // LL
    t.insert(25); // LR
    t.insert(40);
    t.insert(50); // RR
    t.insert(45); // RL

    t.inorder();
}
