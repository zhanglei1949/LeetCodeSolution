#include<iostream>

using namespace std;

vector<int> smallestRange(vector<vector<int>>& nums)
{
    int k = nums.size();
    //merge k arrays, and keep track of the number of labels inside current interval
}
int main()
{
    vector<vector<int>> nums = {{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};
    vector<int> res = smallestRange(nums);
    for (int i = 0; i < res.size(); ++i){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
