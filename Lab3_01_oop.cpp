#include <iostream>
#include <fstream>
#include <queue>
#include<cstdlib>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void insert(TreeNode*& root, int val) {
    if (!root) {
        root = new TreeNode(val);
        return;
    }
    if (val < root->value) {
        insert(root->left, val);
    }
    else {
        insert(root->right, val);
    }
}

void buildTree(TreeNode*& root, int n, ifstream& inputFile) {
    int val;
    for (int i = 0; i < n; i++) {
        val = rand() % 1000;
        inputFile >> val;
        insert(root, val);
    }
}

void traverseInorder(TreeNode* root) {
    if (root) {
        traverseInorder(root->left);
        cout << root->value << " ";
        traverseInorder(root->right);
    }
}

bool search(TreeNode* root, int val) {
    if (!root) {
        return false;
    }
    if (root->value == val) {
        return true;
    }
    if (val < root->value) {
        return search(root->left, val);
    }
    else {
        return search(root->right, val);
    }
}

TreeNode* findMinNode(TreeNode* root) {
    if (!root->left) {
        return root;
    }
    return findMinNode(root->left);
}

void deleteNode(TreeNode*& root, int val) {
    if (!root) {
        return;
    }
    if (val < root->value) {
        deleteNode(root->left, val);
    }
    else if (val > root->value) {
        deleteNode(root->right, val);
    }
    else {
        if (!root->left && !root->right) {
            delete root;
            root = nullptr;
        }
        else if (!root->left) {
            TreeNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if (!root->right) {
            TreeNode* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            TreeNode* minRight = findMinNode(root->right);
            root->value = minRight->value;
            deleteNode(root->right, minRight->value);
        }
    }
}

int getHeight(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void printPrimes(TreeNode* root) {
    if (root) {
        printPrimes(root->left);
        if (isPrime(root->value)) {
            cout << root->value << " ";
        }
        printPrimes(root->right);
    }
}

void printBST(TreeNode* root){
    if(root == nullptr){
        return;
    }
    printBST(root->left);
    cout << root->value << " ";
    printBST(root->right);
}

void deleteFile(){
    remove("input.txt");
}

int main() {
    // 1. Read input file and build BST
    ifstream inputFile("input.txt");
    int n;
    cin >> n;
    inputFile >> n;
    TreeNode* root = nullptr;
    buildTree(root, n, inputFile);
    inputFile.close();
    cout << "Initial binary tree:";
    printBST(root);
    cout << endl;
    // 2. Traverse and print BST in order
    cout << "BST in order: ";
    traverseInorder(root);
    cout << endl;

    // 3. Search for a value
    int valToSearch;
    cout << "Enter a value to search: ";
    cin >> valToSearch;
    if (search(root, valToSearch)) {
        cout << valToSearch << " is in the tree." << endl;
    }
    else {
        cout << valToSearch << " is not in the tree." << endl;
    }

    // 4. Delete a node
    int valToDelete;
    cout << "Enter a value to delete: ";
    cin >> valToDelete;
    deleteNode(root, valToDelete);
    cout << "Binary tree after deleting a node:";
    printBST(root);
    cout << endl;

    // 5. Print the height of the BST
    int height = getHeight(root);
    cout << "Height of BST: " << height << endl;

    // 6. Print prime numbers in the BST
    cout << "Prime numbers in BST: ";
    printPrimes(root);
    cout << endl;
    deleteFile();
    return 0;
}