#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int> &nums)
{
    //binary search
    int left = 0;
    int right = nums.size()-1;
    while (left < right){
        if (nums[left] > nums[right] && right == left+1){
            return nums[right];
        }
        if (nums[left] < nums[right]){
            return nums[left];
        }
        if (nums[left] > nums[right]){
            if (nums[(left+right)/2] > nums[left])
                left = (left+right)/2;
            else right = (left+right)/2;
        }
    }
    if (left==right) return nums[left];
}
int main()
{
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    cout<<findMin(nums);
}
