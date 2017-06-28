#include<iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int isBalancedInt(TreeNode *root)
// if balance return the height, else return -1;
{
    if (root==NULL) return 0;
    int left = isBalancedInt(root->left);
    int right = isBalancedInt(root->right);
    if (left==-1 || right==-1) return -1;
    else if (left <= right+1 && left >= right-1) return max(left, right)+1;
    else return -1;
}
bool isBalanced(TreeNode* root)
{
    if (root==NULL) return true;
    else {
        int res = isBalancedInt(root);
        if (res==-1) return false;
        else return true;
    }
}
int main()
{
    TreeNode * root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(5);
    root->right = new TreeNode(4);
    cout<<isBalanced(root);
}
