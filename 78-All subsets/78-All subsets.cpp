#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int> > &res, vector<int> &tmp, vector<int> & nums, int level, int need)
{
    //cout<<need<<" "<<level<<endl;
    if (need == 0){
        res.push_back(tmp);
        return ;
    }
    for (int i = level; i < nums.size(); ++i){
        tmp.push_back(nums[i]);
        dfs(res, tmp, nums, i+1, need-1);
        tmp.pop_back();
    }
}
vector<vector<int> > subsets(vector<int>& nums)
{
    vector<vector<int> > res;
    vector<int> tmp;
    for (int i = 0; i <= nums.size(); ++i){
        tmp.clear();
        dfs(res, tmp, nums, 0, i);
    }
    return res;
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<vector<int> > res = subsets(nums);
    for (int i = 0; i <res.size(); ++i){
        cout<<i<<": ";
        for (int j = 0; j < res[i].size(); ++j){
            cout<<res[i][j];
        }
        cout<<endl;
    }
    return 1;
}
