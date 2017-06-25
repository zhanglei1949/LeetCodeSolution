#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(vector<vector<int> > & res, vector<int> &nums, vector<int> cur, int start_pos)
{
    res.push_back(cur);
    for (int i = start_pos; i < nums.size(); ++i){
        if (i != start_pos && nums[i-1] == nums[i])
            continue;
        else {
            cur.push_back(nums[i]);
            dfs(res, nums, cur, i+1);
            cur.pop_back();
        }
    }
}
vector<vector<int> > subsetsWithDup(vector<int>& nums)
{
    int len = nums.size();
    vector<vector<int> > res;
    sort(nums.begin(), nums.end());
    vector<int> cur;
    dfs(res, nums, cur, 0);
    return res;
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    //nums.push_back(3);
    //nums.push_back(3);
    //nums.push_back(3);
    vector<vector<int> > res = subsetsWithDup(nums);
    for (int i = 0; i < res.size(); ++i){
        for (int j = 0; j < res[i].size(); ++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
