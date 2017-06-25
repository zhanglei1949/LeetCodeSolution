#include<iostream>
#include<vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
void inorderTraversal(TreeNode *root, vector<int> &res)
{
    if (root == NULL) return ;
    inorderTraversal(root->left, res);
    res.push_back(root->val);
    inorderTraversal(root->right, res);
}
vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> res;
    inorderTraversal(root, res);
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> res = inorderTraversal(root);
    for (int i = 0; i < res.size(); ++i){
        cout<<res[i]<<" ";
    }
}
