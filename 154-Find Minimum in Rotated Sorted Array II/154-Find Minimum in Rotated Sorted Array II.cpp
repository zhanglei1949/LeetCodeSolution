#include<iostream>
#include<vector>
using namespace std;
int StupidfindMin(vector<int>& nums)
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
int findMin(vector<int> & nums)
{
    int len = nums.size();
    int low = 0;
    int high = len-1;
    int mid;
    while (low < high){
        mid = low + (high - low)/2;
        if (nums[mid] > nums[high]){
            //means left is still at first part
            low = mid+1;
        }
        else if (nums[mid] < nums[high]){
            //mid is on the second part
            high = mid;
        }
        else {
            //nums[mid] == nums[high], hard to tell
            high = high - 1;
        }
    }
    return nums[low];
}
int main()
{
    //vector<int> nums = {4,5,6,7,7,7,0,1,1,2,3,3};
    vector<int> nums = {3,1,3,3,3};
    cout<<findMin(nums);
}
