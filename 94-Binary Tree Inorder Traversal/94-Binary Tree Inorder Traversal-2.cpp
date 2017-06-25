#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
vector<int> inorderTraversal(TreeNode* root)
{
    //non-recursive implementation
    vector<int> res;
    stack<TreeNode *> s;
    TreeNode *cur = root;
    while (cur != NULL || !s.empty()){
        //first left->root->right
        while (cur){
            s.push(cur);
            cur=cur->left;
        }
        if (!s.empty()){
            TreeNode *tmp = s.top();
            s.pop();
            res.push_back(tmp->val);
            cur = tmp->right;
        }

    }
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
