#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int> > levelOrder(TreeNode* root)
{
    vector<vector<int> > res;
    vector<int> level;
    queue<TreeNode *> pre;
    queue<TreeNode *> cur;
    if (!root) return res;
    pre.push(root);
    while (!pre.empty()){
        while (!pre.empty()){
            TreeNode *tmp = pre.front();
            level.push_back(tmp->val);
            pre.pop();
            if (tmp){
                if (tmp->left) cur.push(tmp->left);
                if (tmp->right) cur.push(tmp->right);
            }
        }
        pre = cur;
        //cout<<cur.size()<<endl;
        //clear cur
        while (!cur.empty()) cur.pop();
        res.push_back(level);
        level.clear();
    }
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    //root->right = new TreeNode(2);
    //root->left->left = new TreeNode(3);
    //root->left->right = new TreeNode(4);
    //root->right->left = new TreeNode(4);
    //root->right->right = new TreeNode(3);
    //root->right->right->right = new TreeNode(5);
    //root->left->left->left = new TreeNode(6);
    //root = NULL;
    vector<vector<int> > res = levelOrder(root);
    for (int i = 0; i < res.size(); ++i){
        for (int j = 0; j < res[i].size(); ++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
