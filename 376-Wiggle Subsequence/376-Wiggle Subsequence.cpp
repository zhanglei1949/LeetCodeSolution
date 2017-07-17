#include<iostream>
#include<vector>
using namespace std;
int wiggleMaxLength(vector<int>& nums)
{
    int len = nums.size();
    if (len <= 1) return len;
    vector<int> up(len, 0);
    //up[i] represent the maximum length of subsequences ended with nums[i] and ascending.
    vector<int> down(len, 0);
    //down[i] represent the maximum length of subsequences ended with nums[i] and descending.
    up[0]=1;
    down[0]=1;
    //if (nums[i] > nums[i-1])
    //    up[i] = down[i-1]+1;
    //    down[i] = down[i-1]// how could this be true?? down[i] == down[j] (j < i) only sequence i-j is acsending
    //else if (nums[i] < nums[i-1]
    //        down[i] = up[i-1] + 1;
    //        up[i] = up[i]
    for (int i = 1; i < len; ++i){
        if (nums[i] > nums[i-1]){
            up[i] = down[i-1] + 1;
            down[i] = down[i-1];
        }
        else if (nums[i] < nums[i-1]){
            up[i] = up[i-1];
            down[i] = up[i-1] + 1;
        }
        else {
            up[i] = up[i-1];
            down[i] = down[i-1];
        }
    }
//    for (int i = 0; i < len; ++i){
//        cout<<up[i]<<" ";
//    }
//    cout<<endl;
//    for (int i = 0; i < len; ++i){
//        cout<<down[i]<<" ";
//    }
//    cout<<endl;
    return max(down[len-1], up[len-1]);
}
int main()
{
    vector<int> nums={1,2,5,10,13,15,110,115,1116,118};
    cout<<wiggleMaxLength(nums)<<endl;
}
/*
    int len = nums.size();
    if (len <= 2) return len;
    vector<int> dp(1, 0);
    //dp[i] is the maximum length end with nums[i];
    vector<int> flag(len, 0);
    //flag[i] = 1: the next element has to be greater than nums[i];
    //flag[i] = -1: the next element has to be smaller than nums[i];
    //flag[i] = 0: the next element can be either;
    dp[0]=1;
    flag[0] = 0;
    for (int i = 1; i < len; ++i){
        //search for at least two precursor
        int cnt = 0;
        //find flag[j]=1, cnt+=2;
        //find flag[j]=-1, cnt+=1;
        for (int j = i-1; j >= 0; --j){
            if (cnt < 2 && flag[j]==1 && nums[i] > nums[j]){
                if (dp[i] > dp[j]+1){

                }
            }
        }
    }
*/
