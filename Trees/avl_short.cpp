#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

TreeNode *rightRotate(TreeNode *node)
{
    TreeNode *lr, *root;

    root = node->left;
    lr = node->left->right;
    node->left->right = node;
    node->left = lr;
    return root;
}

TreeNode *leftRotate(TreeNode *node)
{
    TreeNode *rl, *root;

    root = node->right;
    rl = node->right->left;
    node->right->left = node;
    node->right = rl;
    return root;
}

TreeNode *avlinsert(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        return new TreeNode(key);
    }

    if (root->val > key)
    {
        root->left = avlinsert(root->left, key);
    }
    else
    {
        root->right = avlinsert(root->right, key);
    }

    int heightdiff = height(root->left) - height(root->right);
    if (heightdiff > 1)
    {
        // left side
        if (root->left->val > key)
        {
            // LLL
            root = rightRotate(root);
        }
        else
        {
            // LLR
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        }
    }
    else if (heightdiff < -1)
    {
        if (root->right->val < key)
        {
            // RRR
            root = leftRotate(root);
        }
        else
        {
            // RRL
            root->right = leftRotate(root->right);
            root = leftRotate(root);
        }
    }

    return root;
}

TreeNode *sortedListToBST(vector<int> v)
{
    if (v.size() == 0)
        return nullptr;
    TreeNode *root = nullptr;

    for (int x : v)
    {
        cout << "INSERT " << x << endl;
        root = avlinsert(root, x);
    }

    return root;
}

void printInorder(TreeNode *root)
{
    if (root == nullptr)
        return;

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main()
{
    vector<int> v = {1, 2, 9, 4, 3, 2};
    printInorder(sortedListToBST(v));
    cout<<endl;
}
