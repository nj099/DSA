#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

void insert(TreeNode** root, int data) {
    if (*root == nullptr) {
        *root = new TreeNode{data, nullptr, nullptr};
        return;
    }

    if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

void preorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    TreeNode* root = nullptr;
    insert(&root, 4);
    insert(&root, 2);
    insert(&root, 6);
    insert(&root, 1);
    insert(&root, 3);

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    return 0;
}
