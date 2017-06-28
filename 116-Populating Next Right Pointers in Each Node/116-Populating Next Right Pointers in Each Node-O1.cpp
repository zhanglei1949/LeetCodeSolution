//O(n) solution
#include<iostream>
#include<vector>

using namespace std;
struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
void connect(TreeLinkNode *root) {
    //level traversal
    //1. if we finish the labeling of next of the previous layer, then using pointer next, we can
    // easily do level traversal
    //2. In each layer, start from the leftest node
    TreeLinkNode *pre;
    TreeLinkNode *cur;
    if (!root) return ;
    pre = root;
    cur = NULL;
    while (pre->left){
        cur = pre;
        while (cur){
            cur->left->next = cur->right;
            if (cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }
}
int main()
{
    TreeLinkNode *root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    root->right = new TreeLinkNode(3);
    root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);
    connect(root);
    //cout<<root->val<<" "<<root->left->val<<" "<<root->left->next->val<<endl;
}
