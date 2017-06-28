#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void record(vector<vector<int> > & res, stack<int> & ori)
{
    stack<int> s(ori);
    stack<int> s2;
    vector<int> tmp;
    while (!s.empty()){
        s2.push(s.top());
        s.pop();
    }
    while (!s2.empty()){
        tmp.push_back(s2.top());
        s2.pop();
    }
    res.push_back(tmp);
}
void dfs(TreeNode *root, int need, stack<int> &s, vector<vector<int> > &res)
{
    cout<<need<<endl;
    if (need-root->val==0 && !root->left && !root->right){
        s.push(root->val);
        record(res, s);
        s.pop();
        return ;
    }
    //if (need-root->val < 0) return ;
    s.push(root->val);
    if (root->left) dfs(root->left, need-root->val, s, res);
    if (root->right) dfs(root->right, need-root->val, s, res);
    s.pop();
}
vector<vector<int> > pathSum(TreeNode* root, int sum)
{
    vector<vector<int> > res;
    stack<int> s;
    if (!root) return res;
    dfs(root, sum, s, res);
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(-2);
    root->right = new TreeNode(-3);
//    root->left = new TreeNode(4);
//    root->left->left = new TreeNode(11);
//    root->left->left->left = new TreeNode(7);
//    root->left->left->right = new TreeNode(2);
//    root->right = new TreeNode(8);
//    root->right->left = new TreeNode(13);
//    root->right->right = new TreeNode(4);
//    root->right->right->left = new TreeNode(5);
//    root->right->right->right = new TreeNode(1);
    vector<vector<int> > res = pathSum(root, -5);
    for (int i = 0; i < res.size(); ++i){
        for (int j = 0; j < res[i].size(); ++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
//vector<vector<int> > pathSum(TreeNode* root, int sum)
//{
//    vector<vector<int> > res;
//    stack<TreeNode *> s;
//    if (root==NULL) return res;
//    int curSum = 0;
//    s.push(root);
//    TreeNode *cur = root;
//    while (cur != NULL || !s.empty()){
//        while (cur!=NULL){
//            s.push(cur);
//            curSum += cur->val;
//            cout<<cur->val<<" "<<curSum<<endl;
//            cur = cur->left;
//        }
//        //if (curSum + cur)
//        //if (curSum == sum) record(res, s);
//        cur = s.top();
//        int tmp = cur->val;
//        s.pop();
//        //cout<<cur->val<<" ";
//        cur = cur->right;
//        if (!cur) curSum -= tmp;
//    }
//    return res;
//}
