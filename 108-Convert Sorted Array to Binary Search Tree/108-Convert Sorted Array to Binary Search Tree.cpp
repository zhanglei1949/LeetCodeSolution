#include<iostream>
#include<vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode * sortedArrayToBST(vector<int>& nums, int s, int e)
{
    cout<<"build from "<<s<<" "<<e<<endl;
    TreeNode *root;
    if (s>e){
        return NULL;
    }
    if (s==e){
        root = new TreeNode(nums[s]);
        return root;
    }
    else if (s+1==e){
        root = new TreeNode(nums[s+1]);
        root->left = new TreeNode(nums[s]);
    }
    else {
        root = new TreeNode(nums[(s+e)/2]);
        root->left = sortedArrayToBST(nums, s, (s+e)/2-1);
        root->right = sortedArrayToBST(nums, (s+e)/2+1, e);
        return root;
    }
}
TreeNode * sortedArrayToBST(vector<int>& nums)
{
    return sortedArrayToBST(nums, 0, nums.size()-1);
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    TreeNode *res = sortedArrayToBST(nums);

}
