#include<iostream>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void preOrder(TreeNode* root)
{
    stack<TreeNode *> s;
    //  s.push(root);
    //DO NOT PUSH ROOT AT FIRST TIME
    TreeNode * previous;
    TreeNode *cur = root;
    previous = cur;
    while (cur != NULL || !s.empty()){
        while (cur!=NULL){
            s.push(cur);
            //cout<<cur->val<<" ";
            cur = cur->left;
            if (cur) previous = cur;
        }
        //cout<<endl;
        if (!s.empty()){
            cur = s.top();
            //cout<<"pop "<<cur->val<<endl;
            s.pop();
            if (cur->right){
                previous->left = cur->right;
                previous = cur->right;
                TreeNode *t = cur;
                cur = cur->right;
                t->right = NULL;
            }
            else {
                cur = cur->right;
            }
        }
        //int a;
        //cin>>a;
    }
    while (root){
        root->right = root->left;
        root->left = NULL;
        root = root->right;
    }
}
void print(TreeNode *root)
{
    cout<<root->val<<" ";
    if (root->right) print(root->right);
}
int main()
{
    TreeNode *root = new TreeNode(1);
    //root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    //root->right->right = new TreeNode(6);
    //root->left->left = new TreeNode(3);
    //root->left->right = new TreeNode(4);

    //root->right->right = new TreeNode(6);
    preOrder(root);
    print(root);
}
