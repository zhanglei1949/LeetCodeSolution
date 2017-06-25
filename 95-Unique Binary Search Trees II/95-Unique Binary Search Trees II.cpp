#include<iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 TreeNode * generateTrees(int start, int end, int n, vector<TreeeNode *> &res)
 {
     //generate a subtree in range[start,end]

 }
 vector<TreeNode*> generateTrees(int n)
 {
    vector<TreeNode *> res;
    for (int i = 1; i <= n; ++i){
        TreeNode *root = new TreeNode(i);
        root->left = generateTrees(1,i-1, n, 1, res);
        root->right = generateTrees(i+1, n, n, 1,res);
    }
 }
int main()
{
    int n;
    cin>>n;
    vector<TreeNode *> res = generateTrees(n);
    for (int i = 0; i < res.size(); ++i){

    }
}
