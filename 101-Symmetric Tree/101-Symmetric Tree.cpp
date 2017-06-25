#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isSymmetric_(TreeNode *left, TreeNode* right)
{
    if (left==NULL && right==NULL) return true;
    else if (left==NULL || right ==NULL) return false;
    else {
        if (left->val!=right->val) return false;
        return isSymmetric_(left->left, right->right) && isSymmetric_(left->right, right->left);
    }
}
bool isSymmetric(TreeNode* root)
{
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return true;
    if (root->left == NULL || root->right == NULL) return false;
    if (root->left->val != root->right->val) return false;
    return isSymmetric_(root->left, root->right);
}
bool isSymmetric2(TreeNode *root)
{
    //solving using level trasversal
    stack<TreeNode *> pre;
    stack<TreeNode *> cur;
    pre.push(root);
    int level = 0;
    while (!pre.empty()){
        level+=1;
        //the level of poped node
        TreeNode *tmp = pre.top();
        pre.pop();
        if (!tmp)
            continue;
        else {
            if (level%2){
                if (tmp->right->val == dd)
                cur.push(pre->right);
                cur.push(pre->left);
            }


        }
    }
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    cout<<isSymmetric(root);
}
