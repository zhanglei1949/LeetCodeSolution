#include<iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x):val(x),left(NULL), right(NULL){}
};
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p==NULL && q == NULL) return true;
    else if(p == NULL || q == NULL) return false;
    if (p->val == q->val) return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    return false;
}
int main()
{
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->left->right = new TreeNode(2);
    root1->right = new TreeNode(4);

    TreeNode *root2 = new TreeNode(3);
    root2->left = new TreeNode(1);
    root2->left->right = new TreeNode(2);
    root2->right = new TreeNode(4);
    cout<<isSameTree(NULL, root1);
}
