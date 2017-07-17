#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>

using namespace std;
int _longestConsecutive(vector<int>& nums)
{
    map<int, int> m;
    map<int, int> show;
    int len = nums.size();
    if (len ==0) return 0;
    if (len==1) return 1;
    //m[i] = 0,1,2,3
    //       i-1, i+1(00,01,10,11)
    int maximum = nums[0];
    int minimum = nums[0];
    m[nums[0]-1] = 2;
    m[nums[0]+1] = 1;
    show[nums[0]] = 1;
    for (int i = 1; i < len; ++i){
        if (show[nums[i]]) continue;
        m[nums[i]-1] +=2;
        m[nums[i]+1] +=1;
        show[nums[i]] = 1;
        maximum = max(maximum, nums[i]);
        minimum = min(minimum, nums[i]);
    }
    int res = 0;
    int cnt = 0;
    bool flag = false;
    for (int i = minimum; i <= maximum; ++i){
        cout<<m[i]<<" ";
        if (m[i]==3) cnt+=1;
        else{
            if (!flag && m[i]==2) flag = true;
            if (cnt > 0) res = max(res, cnt);
            cnt = 0;
        }
    }
    cout<<endl;
    if (res==0 && flag) return 2;
    if (res == 0) return 1;
    return res+2;
}
int __longestConsecutive(vector<int>& nums)
{
    int cnt = 0;
    int res = 0;
    sort(nums.begin(),nums.end());
    for (int i = 0; i < nums.size()-1; ++i){
        //cout<<nums[i]<<" ";
        if (nums[i]==nums[i+1]-1){
            cnt+=1;
        }
        else if (nums[i]!=nums[i+1]){
            if (cnt > 0) res = max(res, cnt);
            cnt = 0;
        }
    }
    res = max(cnt, res);
    //cout<<endl;
    return res;
}
int longestConsecutive(vector<int> &nums)
{
    unordered_map<int, int> m;
    int res = 0;
    int len = nums.size();

    for (int i = 0; i < len; ++i){
        if (!m[nums[i]]){
            int left = m[nums[i]-1];
            int right = m[nums[i]+1];

            m[nums[i]] = left+right+1;
            if (left) m[nums[i]-left] = left+right+1;
            if (right) m[nums[i]+right] = left+right+1;
            res = max(res, left+right+1);
        }
    }
    return res;

}
int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);
//    nums.push_back(200);
//    nums.push_back(1);
//    nums.push_back(3);
//    nums.push_back(2);
    cout<<longestConsecutive(nums);
}
