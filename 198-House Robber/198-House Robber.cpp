#include<iostream>
#include<vector>
using namespace std;

int rob(vector<int>& nums)
{
    int len = nums.size();
    vector<int> dp(len, 0);
    vector<int> flag(len+1, 0);
    dp[0] = nums[0];
    flag[0] = 1;
    if (nums[1] > dp[0]){
        dp[1] = nums[1];
        flag[1] = 1;
    }
    else {
        dp[1] = dp[0];
        flag[1] = 0;
    }
    int maximum = dp[1];
    for (int i = 2; i < len; ++i){
        if (dp[i-1] > dp[i-2] + nums[i]){
            dp[i] = dp[i-1];
            flag[i] = 0;
        }
        else {
//            if (flag[i-1] == 1){
//                dp[i] = dp[i-1];
//                flag[i] = 0;
//            }
//            else {
                dp[i] = dp[i-2] + nums[i];
                flag[i] = 1;
            //}
        }
        maximum = max(maximum, dp[i]);
    }
    //for (int i = 0; i < len; ++i) cout<<dp[i]<<" ";
    //cout<<endl;
    return maximum;
}
int main()
{
    //vector<int> nums = {1,3,2,5,3,3,4,5,1,2};
    vector<int> nums = {1,1,3,2,1};
    cout<<rob(nums)<<endl;
}
