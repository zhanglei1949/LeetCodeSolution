#include<iostream>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int minDepth(TreeNode* root)
{
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty()){
        int len = q.size();
        level+=1;
        for (int i = 0; i < len; ++i){
            TreeNode *tmp = q.front();
            q.pop();
            if (!tmp->left && !tmp->right) return level;
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }
    }
    return level;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    //root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(2);
    cout<<minDepth(root);
}
