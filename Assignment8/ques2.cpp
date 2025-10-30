#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int k): key(k), left(nullptr), right(nullptr) {}
};

/* ---------- Basic BST Utilities ---------- */

// Insert key into BST
Node* insertBST(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key)  root->left  = insertBST(root->left,  key);
    else if (key > root->key) root->right = insertBST(root->right, key);
    // Ignore duplicates; or handle as you wish
    return root;
}

// Recursive search
Node* searchRecursive(Node* root, int key) {
    if (!root || root->key == key) return root;
    if (key < root->key) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

// Iterative search (non-recursive)
Node* searchIterative(Node* root, int key) {
    Node* cur = root;
    while (cur) {
        if (key == cur->key) return cur;
        cur = (key < cur->key) ? cur->left : cur->right;
    }
    return nullptr;
}

// Minimum element node in BST (leftmost)
Node* minNode(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

// Maximum element node in BST (rightmost)
Node* maxNode(Node* root) {
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}

/* ---------- Inorder Successor / Predecessor ---------- */
/*
Successor of key x:
1) If node(x) has a right subtree -> successor is min(node(x)->right)
2) Else -> lowest ancestor for which x lies in its left subtree
We can do this in O(h) with a single walk.
*/
Node* inorderSuccessor(Node* root, int key) {
    Node* succ = nullptr;
    Node* cur = root;
    while (cur) {
        if (key < cur->key) {
            succ = cur;           // potential successor (go left)
            cur = cur->left;
        } else if (key > cur->key) {
            cur = cur->right;     // go right
        } else { // found node
            if (cur->right) succ = minNode(cur->right);
            break;
        }
    }
    return succ; // nullptr if none
}

/*
Predecessor of key x:
1) If node(x) has a left subtree -> predecessor is max(node(x)->left)
2) Else -> highest ancestor for which x lies in its right subtree
*/
Node* inorderPredecessor(Node* root, int key) {
    Node* pred = nullptr;
    Node* cur = root;
    while (cur) {
        if (key > cur->key) {
            pred = cur;           // potential predecessor (go right)
            cur = cur->right;
        } else if (key < cur->key) {
            cur = cur->left;      // go left
        } else { // found node
            if (cur->left) pred = maxNode(cur->left);
            break;
        }
    }
    return pred; // nullptr if none
}

int main() {

    vector<int> keys = {20,10,30,5,15,25,40,18};
    Node* root = nullptr;
    for (int k : keys) root = insertBST(root, k);

    // (a) Search (recursive & iterative)
    int x = 15, y = 26;
    cout << "[Search Recursive] 15: " << (searchRecursive(root, x) ? "Found" : "Not Found") << "\n";
    cout << "[Search Iterative] 26: " << (searchIterative(root, y) ? "Found" : "Not Found") << "\n";

    // (b) Maximum element
    Node* mx = maxNode(root);
    cout << "Max element: " << (mx ? to_string(mx->key) : string("N/A")) << "\n";

    // (c) Minimum element
    Node* mn = minNode(root);
    cout << "Min element: " << (mn ? to_string(mn->key) : string("N/A")) << "\n";

    // (d) In-order successor
    int sKey = 15;
    Node* succ = inorderSuccessor(root, sKey);
    cout << "In-order Successor of " << sKey << ": " 
         << (succ ? to_string(succ->key) : string("None")) << "\n";

    // (e) In-order predecessor
    int pKey = 15;
    Node* pred = inorderPredecessor(root, pKey);
    cout << "In-order Predecessor of " << pKey << ": " 
         << (pred ? to_string(pred->key) : string("None")) << "\n";

    return 0;
}
