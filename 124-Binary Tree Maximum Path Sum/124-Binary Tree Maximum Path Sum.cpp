#include<iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int a):val(a),left(NULL), right(NULL) {}
};
int max(int a, int b, int c)
{
    return max(max(a,b),max(b,c));
}
int maxPathSum(TreeNode* root, int & maximum)
{
    if (root == NULL) return 0;
    int left = maxPathSum(root->left, maximum);
    int right = maxPathSum(root->right, maximum);
    int for_return = max(left+root->val, right+root->val, left+right+root->val);

    maximum = max(maximum, root->val, for_return);
    //cout<<root->val<<" "<<maximum<<" "<<for_return<<endl;
    return for_return;
}
int maxPathSum(TreeNode *root)
{
    if (!root) return 0;
    int maximum = 0;
    maxPathSum(root, maximum);
    return maximum;
}
int main()
{
    TreeNode *root = new TreeNode(-1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(-4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(-7);
    cout<<maxPathSum(root);
}
