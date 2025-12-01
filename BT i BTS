#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) {
        val = v;
        left = right = nullptr;
    }
};

struct BT {
    Node* root=nullptr;

    void insert(int v) {
        if (root == nullptr) {
            root = new Node(v);
            return;
        }
        
        queue<Node*> t;
        t.push(root);
        while(!t.empty()){
            Node* cur=t.front();
            t.pop();
            if(cur->left==nullptr){
                cur->left=new Node(v);
                return;
            }
            t.push(cur->left);
            if(cur->right==nullptr){
                cur->right=new Node(v);
                return;
            }
            t.push(cur->right);
        }
    }
    
    bool find(Node* n,int x) {
        if (n == nullptr) return false;
        if (n->val == x) return true;
        return find(n->left, x) || find(n->right, x);    }
     bool find(int x) {
        return find(root, x);
    }
};

////////////////////////////////////////

struct BST {
    Node* root=nullptr;

    Node* insert(Node* n, int v) {
        if (n == nullptr) {
            return new Node(v);
        }
        if (v < n->val)
            n->left = insert(n->left, v);
            
        else if (v > n->val)
            n->right = insert(n->right, v);
            
        return n;
    }

    void insert(int v) {
        root = insert(root, v);
    }
    
    bool find(Node* n, int x) {
        if (!n) return false;
        if (n->val == x) return true;
        if (x < n->val)
            return find(n->left, x);
        else
            return find(n->right, x);
    }

    bool find(int x) {
        return find(root, x);
    }
};

//////////////////////////////////////

void preorderR(Node* n) {
    if (!n) return;
    cout << n->val << " ";
    preorderR(n->left);
    preorderR(n->right);
}

void inorderR(Node* n) {
    if (!n) return;
    inorderR(n->left);
    cout << n->val << " ";
    inorderR(n->right);
}

void postorderR(Node* n) {
    if (!n) return;
    postorderR(n->left);
    postorderR(n->right);
    cout << n->val << " ";
}

///////////////////////////////////////

void preorderI(Node* root) {
    if (!root) return;
    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* cur = s.top(); s.pop();
        cout << cur->val << " ";

        if (cur->right) s.push(cur->right);
        if (cur->left) s.push(cur->left);
    }
    cout << "\n";
}

void inorderI(Node* root) {
    stack<Node*> s;
    Node* cur = root;
    while (cur || !s.empty()) {
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top(); s.pop();
        cout << cur->val << " ";
        cur = cur->right;
    }
    cout << "\n";
}

void postorderI(Node* root) {
    if (!root) return;
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* cur = s1.top(); s1.pop();
        s2.push(cur);
        if (cur->left) s1.push(cur->left);
        if (cur->right) s1.push(cur->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->val << " ";
        s2.pop();
    }
    cout << "\n";
}

///////////////////////////////////

void bfs(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        cout << cur->val << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    cout << "\n";
}

///////////////////////////////////

int sum(Node* n) {
    if (!n) return 0;
    return n->val + sum(n->left) + sum(n->right);
}

int main() {
    BT bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);

    cout << "DFS рекурзија - Preorder: "; preorderR(bt.root); cout << "\n";
    cout << "DFS рекурзија - Inorder: "; inorderR(bt.root); cout << "\n";
    cout << "DFS рекурзија - Postorder: "; postorderR(bt.root); cout << "\n";

    cout << "DFS без рекурзија - Preorder: "; preorderI(bt.root);
    cout << "DFS без рекурзија - Inorder: "; inorderI(bt.root);
    cout << "DFS без рекурзија - Postorder: "; postorderI(bt.root);

    cout << "BFS: "; bfs(bt.root);
    
    cout << "Сума BT: " << sum(bt.root) << "\n";

    BST bst;
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(10);
    bst.insert(25);
    bst.insert(35);
    bst.insert(50);

    cout << "DFS рекурзија - Preorder: "; preorderR(bst.root); cout << "\n";
    cout << "DFS рекурзија - Inorder: "; inorderR(bst.root); cout << "\n";
    cout << "DFS рекурзија - Postorder: "; postorderR(bst.root); cout << "\n";

    cout << "DFS без рекурзија - Preorder: "; preorderI(bst.root);
    cout << "DFS без рекурзија - Inorder: "; inorderI(bst.root);
    cout << "DFS без рекурзија - Postorder: "; postorderI(bst.root);

    cout << "BFS: "; bfs(bst.root);

    cout << "Сума BST: " << sum(bst.root) << "\n";
    
    return 0;
}
