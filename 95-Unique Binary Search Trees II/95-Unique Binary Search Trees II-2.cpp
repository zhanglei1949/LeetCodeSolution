#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 vector<TreeNode *> generateSubTrees(int start, int end)
 {
     vector<TreeNode *> res;
     //generate a subtree in range[start,end]
     if (start > end){
        res.push_back(NULL);
        return res;
     }
     else if (start == end){
        TreeNode *node = new TreeNode(start);
        res.push_back(node);
        return res;
     }
     else {
        for (int i = start; i <= end; ++i){
            vector<TreeNode *> left = generateSubTrees(start, i-1);
            vector<TreeNode *> right = generateSubTrees(i+1, end);

            for (int j = 0; j < left.size(); ++j){
                for (int k = 0; k < right.size(); ++k){
                    // can not move out
                    TreeNode *cur = new TreeNode(i);
                    cur->right = right[k];
                    cur->left = left[j];
                    res.push_back(cur);
                }
            }
        }
        return res;

     }
 }
 vector<TreeNode*> generateTrees(int n)
 {
    return generateSubTrees(1, n);
 }
 void print(TreeNode *root)
 {
     cout<<root->val<<" ";
     if (root->left) print(root->left);
     if (root->right) print(root->right);
 }
int main()
{
    int n;
    cin>>n;
    vector<TreeNode *> res = generateTrees(n);
    for (int i = 0; i < res.size(); ++i){
        print(res[i]);
        cout<<endl;
    }
}
