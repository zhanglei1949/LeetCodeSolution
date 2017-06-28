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
    vector<TreeLinkNode *> pre;
    vector<TreeLinkNode *> cur;
    pre.push_back(root);
    if (!root) return ;
    while (pre.size()>0){
        cur.clear();
        for (int i = 0; i < pre.size(); ++i){
            TreeLinkNode * tmp = pre[i];
            if (tmp->left) cur.push_back(tmp->left);
            if (tmp->right) cur.push_back(tmp->right);
        }
        pre = cur;
        for (int i = 0; i < int(cur.size())-1; ++i){
            cout<<cur[i]->val<<"->"<<cur[i+1]->val<<endl;
            cur[i]->next = cur[i+1];
        }
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
