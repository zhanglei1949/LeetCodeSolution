#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool dfs(TreeNode *root, int need)
    {
        if (root->val==need && !root->left && !root->right) return true;
        return ( (root->left && dfs(root->left, need-root->val)) || (root->right && dfs(root->right, need-root->val)) );
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (root==NULL) return false;
        //if (root->val==sum) return true;
        return dfs(root,sum);
    }
