#include<iostream>
#include<vector>
using namespace std;
int findMin(vector<int>& nums)
{
    int len = nums.size();
    if (len == 1) return nums[0];
    int left = 0;
    int right = len-1;
    while (left <= right)
    {
        if (nums[left] < nums[right]) return nums[left];
        if (nums[left] >= nums[right] && left+1 == right) return nums[right];
        cout<<left<<" "<<right<<endl;
        int mid = (left+right)/2;
        if (nums[mid] > nums[left])
            left = mid;
        else if (nums[mid] <= nums[right])
            right = mid;
        else right = mid;
        int a;
        cin>>a;
    }
    return nums[left];
}
int main()
{
    //vector<int> nums = {4,5,6,7,7,7,0,1,1,2,3,3};
    vector<int> nums = {3,1,3,3,3};
    cout<<findMin(nums);
}
