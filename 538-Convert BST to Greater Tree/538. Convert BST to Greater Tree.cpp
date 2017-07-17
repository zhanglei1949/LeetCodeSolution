#include<iostream>

using namespace std;

struct TreeNode
{
    TreeNode *left, *right;
    int val;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
};
void postOrderTraversal(TreeNode *root, int & sum)
{
    if (!root) return ;
    postOrderTraversal(root->right, sum);
    sum += root->val;
    root->val = sum;
    postOrderTraversal(root->left, sum);
}
void print(TreeNode *root)
{
    if (!root) return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}
TreeNode* convertBST(TreeNode* root)
{
    int sum = 0;
    postOrderTraversal(root,sum);
    return root;
}
int main()
{
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(8);
    root->right->right = new TreeNode(9);
    root->right->left = new TreeNode(7);
    TreeNode *res = convertBST(root);
    print(res);
}
