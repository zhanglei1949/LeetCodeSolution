#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

/*dfs solution
    void dfs(vector<int> & nums, int &target, int level, int need, int &curSum, int &closestSum)
    {
        cout<<level<<" "<<need<<" "<<curSum<<" "<<closestSum<<" "<<target<<endl;
        //need: numbers needed
        //level: where this search will start from

        if (need==0){
            if (abs(target-curSum) < abs(closestSum-target))
                closestSum = curSum;
                return ;
        }
        if (level >= nums.size()) return ;
        for (int i = level; i <= nums.size()-need; ++i){
            curSum += nums[i];
            dfs(nums, target, i+1, need-1, curSum, closestSum);
            curSum -= nums[i];
        }
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int closestSum = target+1000;
        int curSum = 0;
        dfs(nums, target, 0, 3, curSum, closestSum);
        return closestSum;
    }
*/
int threeSumClosest(vector<int> &nums, int target)
{
    int len = nums.size();
    int closestSum = nums[0]+nums[1]+nums[2];
    if (len == 3) return closestSum;

    sort(nums.begin(), nums.end());
    //using  two pointers
    for (int i = 0; i < len-2; ++i){
        int j = i+1;
        int k = len-1;
        //two pointer
        while (j < k){
            int tmp = nums[i]+nums[j]+nums[k];
            if (abs(tmp - target) < abs(closestSum - target)){
                closestSum = tmp;
                cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
            }
            if (tmp > target) k--;
            else if (tmp < target) j++;
            else return closestSum;
        }
    }
    return closestSum;
}
int main()
{
    vector<int> nums(5,1);
    nums[2] = -1;
    nums[3] = -1;
    nums[4] = 3;
    int target = -1;
    cout<<threeSumClosest(nums, target);
}
