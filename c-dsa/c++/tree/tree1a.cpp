#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a new node
    TreeNode(int value) {
        data = value;
        left = right = nullptr;
    }
};

void insert(TreeNode*& root, int data) {
    if (root == nullptr) {
        root = new TreeNode(data);
        return;
    }

    if (data < root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

void preorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    TreeNode* root = nullptr;
    cout << "Create the binary tree:" << endl;
    insert(root, 4);
    insert(root, 3);
    insert(root, 5);
    insert(root, 1);
    insert(root, 9);

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
