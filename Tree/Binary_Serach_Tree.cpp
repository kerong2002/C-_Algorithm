//2023/05/29 kerong
/*
   Algorithm : Binary Search Tree
    Time complexity : O(log N)
   Space complexity : O(log N)
*/

#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            node = new TreeNode(value);
            return node;
        }
        if (value > node->val) {
            node->right = insert(node->right, value);
        }
        else if (value < node->val) {
            node->left = insert(node->left, value);
        }
        return node;
    }

    TreeNode* findMaxNode(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }

        while (node->right != nullptr) {
            node = node->right;
        }

        return node;
    }

    TreeNode* remove(TreeNode* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value > node->val) {
            node->right = remove(node->right, value);
        }
        else if (value < node->val) {
            node->left = remove(node->left, value);
        }
        else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            else {
                TreeNode* maxNode = findMaxNode(node->left);
                node->val = maxNode->val;
                node->left = remove(node->left, maxNode->val);
            }
        }

        return node;
    }

    void printInorder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        printInorder(node->left);
        cout << node->val << " ";
        printInorder(node->right);
    }

    void printPostorder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        printPostorder(node->left);
        printPostorder(node->right);
        cout << node->val << " ";
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void remove(int value) {
        root = remove(root, value);
    }

    void printInorder() {
        printInorder(root);
    }

    void printPostorder() {
        printPostorder(root);
    }

};

int main() {
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    cout << "Binary Search Tree (Inorder): ";
    bst.printInorder();
    cout << endl;
    cout << "Binary Search Tree (Postorder): ";
    bst.printPostorder();
    cout << endl;
    /*
           5
          / \
         /   \
        3     7
       / \   / \
      2   4 6   8
    */

    bst.remove(3);
    cout << "Binary Search Tree after removing 3 (Inorder): ";
    bst.printInorder();
    cout << endl;
    cout << "Binary Search Tree (Postorder): ";
    bst.printPostorder();
    cout << endl;

    /*
           5
          / \
         /   \
        2     7
         \   / \
          4 6   8
    */


    return 0;
}
