#include<iostream>
#include<queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findBottomLeftValue(TreeNode* root)
{
    queue<TreeNode *> q_pre;
    queue<TreeNode *> q_next;
    q_pre.push(root);
    int res = 0;
    while (!q_pre.empty()){
        while (!q_next.empty()) q_next.pop();
        res = q_pre.front()->val;
        while (!q_pre.empty()){
            TreeNode *p = q_pre.front();
            q_pre.pop();
            if (p->left) q_next.push(p->left);
            if (p->right) q_next.push(p->right);
        }
        q_pre = q_next;
    }
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(2);
    root->right = new TreeNode(4);
    //root->right->left = new TreeNode(3);
    cout<<findBottomLeftValue(root);
}
