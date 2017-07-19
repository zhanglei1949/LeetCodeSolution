#include<iostream>
#include<vector>
#include<map>
using namespace std;

int NaivefindMaxLength(vector<int>& nums)
{
    int len = nums.size();
    vector<vector<int> > flag(len, vector<int>(len, 0));
    int maximum = 0;
    for (int i = 0; i < len; ++i){
        int tmp = 0;
        for (int j = i; j < len; ++j){
            if (nums[j]==0) tmp+= -1;
            else tmp += 1;
            //cout<<tmp<<" ";
            if (tmp==0) maximum = max(maximum, j-i+1);
        }
        //cout<<endl;
    }
    return maximum;
}
int secondNaivefindMaxLength(vector<int>& nums)
{
    int len = nums.size();
    vector<int> flag(len, 0);
    int maximum = 0;
    if (nums[0]==0) flag[0] = -1;
    else flag[0] = 1;
    for (int i = 1; i < len; ++i){
        if (nums[i]==0) flag[i] = flag[i-1] - 1;
        else flag[i] = flag[i-1] + 1;
        if (flag[i] == 0) maximum = max(maximum, i+1);
    }
    for (int i = 0; i < len; ++i){
        for (int j = i+1; j < len; ++j){
            if (nums[i]==0) flag[j] += 1;
            else flag[j] -= 1;
            if (flag[j] == 0) maximum = max(maximum, j-i);
        }
    }
    return maximum;
}
int findMaxLength(vector<int> & nums)
{
    map<int, int> m;
    m[0] = -1;
    //why?
    //if we take zeros as -1s, then we have to find the longest contiguous array with sum equal to 0;
    int sum = 0;
    int res = 0;
    int len = nums.size();
    for (int i = 0; i < len; ++i){
        //nums[0:i]==nums[0:j] -> nums[i+1:j]==0
        if (nums[i]==0) sum -= 1;
        else sum += 1;
        if (m.count(sum) > 0){
            res = max(res, i - m[sum]);
        }
        else m[sum] = i;
    }
    for (map<int, int>::iterator iter = m.begin(); iter != m.end(); ++iter){
        //cout<<iter->first<<" "<<iter->second<<endl;
    }
    return res;
}
int main()
{
    vector<int> nums = {1,0,1,1,1,0,0,1,0};
    cout<<findMaxLength(nums)<<endl;
}
