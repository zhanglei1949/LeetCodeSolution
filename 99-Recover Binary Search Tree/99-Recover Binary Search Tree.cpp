#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void recoverTree(TreeNode* root)
{
    if (!root) return ;
    //two elements are swapped, so we have to find that two elements and swap them
    stack<TreeNode *> s;
    vector<TreeNode *> vec;
    vector<int> wrong;
    TreeNode *cur = root;
    while (cur || !s.empty()){
        while (cur){
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        vec.push_back(cur);
        //cout<<cur->val<<" ";
        cur = cur->right;
    }
    //for (int i = 0; i < vec.size(); ++i) cout<<vec[i]->val<<" ";
    //cout<<endl;
    bool flag = false;
    for (int i = 0; i < vec.size()-1; ++i){
        if (vec[i]->val > vec[i+1]->val){
            if (!flag){
                wrong.push_back(i);
                flag = true;
            }
            else {
                wrong.push_back(i+1);
            }
        }
    }
    //cout<<wrong.size()<<endl;
    if (wrong.size()==1){
        int tmp = vec[wrong[0]]->val;
        vec[wrong[0]]->val = vec[wrong[0]+1]->val;
        vec[wrong[0]+1]->val = tmp;
    }
    else if (wrong.size()==2){
        int tmp = vec[wrong[0]]->val;
        vec[wrong[0]]->val = vec[wrong[1]]->val;
        vec[wrong[1]]->val = tmp;
    }

}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    //root->left->right = new TreeNode(2);
    root->right = new TreeNode(1);
    //root->right->right = new TreeNode(4);
    recoverTree(root);
    TreeNode *cur = root;
    stack<TreeNode *> s;
    while (cur || !s.empty()){
        while (cur){
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        cout<<cur->val<<" ";
        cur = cur->right;
    }
}
