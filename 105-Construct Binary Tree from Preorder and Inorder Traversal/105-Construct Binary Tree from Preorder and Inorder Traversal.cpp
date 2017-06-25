#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode * buildTree(vector<int> & preorder, vector<int> & inorder, int ps, int pe, int is, int ie)
{
    TreeNode *root;
    //char c;cin>>c;
    cout<<"build from inorder: "<<"("<<is<<" "<<ie<<")"<<" preorder "<<"("<<ps<<" "<<pe<<")"<<endl;
    //construct tree using [ps, pe), [is, ie)
    if (ps == pe && is == ie) return NULL;
    else if (pe==ps+1 && ie==is+1 && preorder[ps]==inorder[is]){
        root = new TreeNode(inorder[is]);
        return root;
    }
    else if (pe == ps+2 && ie == is+2){
        root = new TreeNode(preorder[ps]);
        if (preorder[ps]==inorder[is])
            root->right = new TreeNode(preorder[ps+1]);
        else root->left = new TreeNode(preorder[ps+1]);
        return root;
    }
    else {
        //find the root, then separately build left part and right part
        int root_inorder_pos = 0;
        vector<int>::iterator iter = find(inorder.begin(), inorder.end(), preorder[ps]);
        root_inorder_pos = iter-inorder.begin()-is;
        root = new TreeNode(preorder[ps]);
        root->left = buildTree(preorder,inorder,ps+1, ps+root_inorder_pos+1, is, is+root_inorder_pos);
        root->right = buildTree(preorder,inorder,ps+root_inorder_pos+1, pe, is+root_inorder_pos+1, ie);
        return root;
    }
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    return buildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
}
int main()
{
    vector<int> preorder;
    vector<int> inorder;
    preorder.push_back(3);
    preorder.push_back(1);
    //preorder.push_back(0);
    preorder.push_back(2);
    preorder.push_back(5);
    preorder.push_back(4);
    preorder.push_back(6);
    //inorder.push_back(0);
    inorder.push_back(1);
    inorder.push_back(2);
    inorder.push_back(3);
    inorder.push_back(4);
    inorder.push_back(5);
    inorder.push_back(6);
    TreeNode *res = buildTree(preorder,inorder);
}
