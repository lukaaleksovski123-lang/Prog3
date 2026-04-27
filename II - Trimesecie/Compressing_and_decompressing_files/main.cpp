#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    unsigned char character;
    int frequency;
    Node *left, *right;

    Node(unsigned char c, int f) 
        : character(c), frequency(f), left(nullptr), right(nullptr) {}

    Node(int f, Node* l, Node* r) 
        : character(0), frequency(f), left(l), right(r) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency;
    }
};

// Генерирање кодови
void generate_codes(Node* node, string code, vector<string>& codes) {
    if (!node) return;

    if (!node->left && !node->right) {
        codes[node->character] = (code.empty() ? "0" : code);
        return;
    }

    generate_codes(node->left, code + "0", codes);
    generate_codes(node->right, code + "1", codes);
}

int main() {

    ifstream input_file("ana_karenina.txt", ios::binary);
    if (!input_file) {
        cout << "Ne moze da se otvori fajlot\n";
        return 1;
    }

    vector<int> frequency(256, 0);
    unsigned char character;

    while (input_file.get(reinterpret_cast<char&>(character))) {
        frequency[character]++;
    }

    // Priority queue
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0)
            pq.push(new Node((unsigned char)i, frequency[i]));
    }

    if (pq.empty()) {
        cout << "Fajlot e prazen.\n";
        return 1;
    }

    // HHuffman дрво
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        pq.push(new Node(left->frequency + right->frequency, left, right));
    }

    Node* root = pq.top();

    vector<string> codes(256);
    generate_codes(root, "", codes);


    input_file.clear();
    input_file.seekg(0);

    // Компресија
    ofstream out("compressed.txt", ios::binary);
    while (input_file.get(reinterpret_cast<char&>(character))) {
        out << codes[character];
    }

    input_file.close();
    out.close();

    // Dekompresija
    ifstream input_file2("compressed.txt", ios::binary);
    ofstream out2("decompressed.txt", ios::binary);

    Node* current = root;
    char bit;

    while (input_file2.get(bit)) {
        if (bit == '0')
            current = current->left;
        else
            current = current->right;

        if (!current->left && !current->right) {
            out2.put(current->character);
            current = root;
        }
    }

    input_file2.close();
    out2.close();

    cout << "Gotovo.\n";

    return 0;
}