#include<iostream>
#include<vector>
using namespace std;

void sortColors_1(vector<int> &nums)
{
    int arr[3] = {0};
    for (int i = 0; i < nums.size(); ++i){
        arr[nums[i]]++;
    }
    nums.clear();
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < arr[i]; ++j){
            nums.push_back(i);
        }
    }
}
void swap(vector<int> &nums, int a, int b)
{
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}
void sortColors(vector<int> &nums)
{
    if (nums.size() <= 1) return ;
    int zero_pointer = 0;
    int two_pointer = nums.size()-1;
    for (int i = 0; i <= two_pointer;++i){// order of these two sentences matters?
        while (nums[i]==2 && i < two_pointer) swap(nums, i, two_pointer--);
        while (nums[i]==0 && i > zero_pointer) swap(nums, i, zero_pointer++);
    }
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(2);
    sortColors(nums);
    for (int i = 0; i < nums.size(); ++i){
        cout<<nums[i]<<" ";
    }
    return 0;
}
