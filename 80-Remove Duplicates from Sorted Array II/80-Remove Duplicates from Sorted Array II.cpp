#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums)
{
    vector<int>::iterator iter;
    int len = nums.size();
    int cnt = 0;
    iter = nums.begin();
    while (iter != nums.end()){
        iter++;
        if (iter != nums.end() && *iter == *(iter-1)){
            cnt+=2;
            iter++;
            while (iter!=nums.end() && *iter==*(iter-1)){
                iter = nums.erase(iter);
            }
        }
        else {
            cnt+=1;
        }
    }
    return cnt;
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    cout<<removeDuplicates(nums)<<endl;
    for (int i = 0; i < nums.size(); ++i){
        cout<<nums[i]<<" ";
    }
}
