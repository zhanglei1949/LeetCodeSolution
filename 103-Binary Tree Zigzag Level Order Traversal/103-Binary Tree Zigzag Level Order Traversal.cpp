#include<iostream>
#include<vector>
#include<deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > res;
    vector<int> level;

    vector<TreeNode *> pre;
    vector<TreeNode *> cur;

    pre.push_back(root);
    bool flag = true;
    while (!pre.empty()){
        for (int i = 0; i < pre.size(); ++i){
            TreeNode *tmp;
            if (flag) tmp = pre[i];
            else tmp = pre[pre.size()-i-1];
            level.push_back(tmp->val);
            if (pre[i]->left) cur.push_back(pre[i]->left);
            if (pre[i]->right) cur.push_back(pre[i]->right);
        }
        res.push_back(level);
        //for (int i = 0; i < level.size(); ++i) cout<<level[i]<<" ";
        //cout<<endl;
        level.clear();
        pre = cur;
        cur.clear();
        flag = !flag;
    }
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);
    root->left->left->left = new TreeNode(9);
    vector<vector<int> > res = zigzagLevelOrder(root);
    for (int i = 0; i < res.size(); ++i){
        for (int j = 0; j < res[i].size(); ++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
