#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;  
        explicit node(int val = 0) {
            data = val;
            left = nullptr;
            right = nullptr;
        }
};


node* insertNode(node* root ,int val);
void printInOrder(node* root);
void printPreOrder(node* root);
void printPostOrder(node* root);
node* searchTree(node* root, int val);
node* deleteTree(node* root, int val);
int height(node* root);

int main() {
    node* root = nullptr;
    root = insertNode(root, 6);
    insertNode(root, 5);
    insertNode(root, 7);
    cout << "\n\n\n\n" << height(root)<<endl;

    deleteTree(root, 5);
 
    cout << "INORDER: ";
    printInOrder(root);
    cout << endl;
    cout << "PREORDER: ";
    printPreOrder(root);
    cout << endl;
    cout << "POSTORDER: ";
    printPostOrder(root);
    cout << endl;
    cout << searchTree(root, 6) << endl;
}


node* insertNode(node* root ,int val) {
    if (root == nullptr) return new node(val);
    
    if (root->data > val) root->left = insertNode(root->left, val);
    else if (root->data < val) root->right = insertNode(root->right,val); 
    
    return root;
}

void printInOrder(node* root) {
    if (root == nullptr) return;
    else {
        printInOrder(root->left);
        cout << root->data << " ";
        printInOrder(root->right);
    }    
}

void printPreOrder(node* root) {
    if (root == nullptr) return;
    else {
        cout << root->data << " ";
        printInOrder(root->left);
        printInOrder(root->right);
    }    
}

void printPostOrder(node* root) {
    if (root == nullptr) return;
    else {
        printInOrder(root->left);
        printInOrder(root->right);
        cout << root->data << " ";
    }    
}

node* searchTree(node* root, int val) {
    if (root == nullptr) return nullptr;
    else if (root->data == val) return root;
    else {
        node* left = searchTree(root->left, val);
        node* right = searchTree(root->right, val);
        if (left != nullptr && right == nullptr) return left;
        else if (left == nullptr && right != nullptr) return right;
        else return nullptr;
    } 
}

node* deleteTree(node* root, int val) {
    if (root == nullptr) return root;
    if (val < root->data) {
        root->left = deleteTree(root->left, val);
        return root;
    }
    else if (val > root->data) {
        root->right = deleteTree(root->right, val);
        return root;
    }
    else {
        if (root->left == nullptr) {
            // OR if both are nullptr
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            node* successorParent = root->right;
            node* successor = root->right;
            while (successor->left != nullptr)
            {
                successorParent = successor;
                successor = successor->left;
            }
            successorParent->left = successor->right;
            root->data = successor->data;
            delete successor;
            return root;
        }
    }
}
int height(node* root) {
    if (root == nullptr) return 0;
    int left = 1+ height(root->left);
    int right = 1+ height(root->right);
    return max(right, left);
}