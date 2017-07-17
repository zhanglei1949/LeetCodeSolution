#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void wrong_dfs(vector<int> &nums, vector<vector<int>> & res, vector<int> &cur, int level)
{
    if (level == nums.size()){
        return ;
        //don't have to push back
    }
    for (int i = level; i < nums.size(); ++i){
        if (i > level && nums[i]==nums[i-1]) continue;
        //can not do this! array is not sorted;
        if (cur.empty() || cur.back() <= nums[i]){
            cur.push_back(nums[i]);
            if (cur.size() > 1) res.push_back(cur);
            wrong_dfs(nums,res, cur, i+1);
            cur.pop_back();
        }
    }
}
void dfs(vector<int> &nums, vector<vector<int>> & res, vector<int> &cur, int level)
{
    if (level == nums.size()){
        return ;
        //don't have to push back
    }
    unordered_set<int> s;
    //for this iteration, remember numbers we have chosen;
    for (int i = level; i < nums.size(); ++i){
        if (i > level && nums[i]==nums[i-1]) continue;
        //can not do this! array is not sorted;
        if (cur.empty() || cur.back() <= nums[i] && s.find(nums[i]) == s.end()){
            cur.push_back(nums[i]);
            if (cur.size() > 1) res.push_back(cur);
            dfs(nums,res, cur, i+1);
            cur.pop_back();
            s.insert(nums[i]);
        }
    }
}
vector<vector<int>> findSubsequences(vector<int>& nums)
{
    vector<vector<int>>res;
    vector<int> cur;
    dfs(nums, res, cur, 0);
    return res;
}

int main()
{
    vector<int> nums = {4,6,7,7};
    vector<vector<int> > res = findSubsequences(nums);
    for (int i = 0; i < res.size(); ++i){
        for (int j = 0; j < res[i].size(); ++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
