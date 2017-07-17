#include<iostream>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int a):val(a),left(NULL), right(NULL) {}
};

void dfs(TreeNode *root, int & sum, int & cur)
    {
        cur = cur*10 + root->val;
        if (!root->left && !root->right){
            sum += cur;
            cur = cur/10;
            return ;
        }
        if (root->left) dfs(root->left, sum, cur);
        if (root->right) dfs(root->right, sum, cur);
        cur = cur/10;
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int cur = 0;
        if (!root) return 0;
        dfs(root, sum, cur);
        return sum;
    }
int main()
{
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    cout<<sumNumbers(root);
}
