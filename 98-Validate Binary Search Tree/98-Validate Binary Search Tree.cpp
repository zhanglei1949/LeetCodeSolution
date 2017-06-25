#include<iostream>
#include<stack>
using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};
bool midOrder(TreeNode *root)
{
    stack<TreeNode *> s;
    TreeNode *cur = root;
    while (cur || !s.empty()){

        while (cur){
            cout<<cur->val<<endl;
            if (cur->left && cur->left->val > cur->val)
                return false;
            s.push(cur);
            cur = cur->left;
        }
        if (!s.empty()){
            cur = s.top();
            s.pop();
            if (cur->right){
                if (cur->right->val < cur->val)
                    return false;

            }
            cur = cur->right;
        }
        //s.pop();
    }
    return true;
}
bool isValidBSTHelper(TreeNode *root, int & min_of_subtree, int &max_of_subtree)
{
    cout<<root->val<<endl;
    int left_son_max = root->val;
    int left_son_min = root->val;
    int right_son_min = root->val;
    int right_son_max = root->val;
    bool res;
    if (root->left ==NULL && root->right ==NULL){
        min_of_subtree = root->val;
        max_of_subtree = root->val;
        return true;
    }
    else if (root->left==NULL){
        res = isValidBSTHelper(root->right, right_son_min, right_son_max) && (right_son_min > root->val);
    }
    else if (root->right==NULL){
        res = isValidBSTHelper(root->left, left_son_min, left_son_max) && (left_son_max < root->val);
    }
    else
        res = isValidBSTHelper(root->right, right_son_min, right_son_max) && (right_son_min > root->val)
            && isValidBSTHelper(root->left, left_son_min, left_son_max) && (left_son_max < root->val);
        //res =  isValidBSTHelper(root->left, left_son_max, 0) && isValidBSTHelper(root->right, right_son_min, 1) && (left_son_max < root->val) && (right_son_min > root->val);
    min_of_subtree = left_son_min;
    max_of_subtree = right_son_max;
    return res;
}
bool isValidBST(TreeNode* root) {
    int min = 0;
    int max = 0;
    return isValidBSTHelper(root, min, max);
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(4);
    cout<<isValidBST(root);
}
