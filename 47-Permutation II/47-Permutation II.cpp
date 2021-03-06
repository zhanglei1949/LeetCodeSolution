#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> nextPermutation(vector<int>& origin)
{
    int tmp;
    int len = origin.size();
    // next permutation
    //first find the last ascending position
    //then find the last element that is greater than position, exchange positions;
    //finally reverse numbers after position
    vector<int> nums;
    nums.assign(origin.begin(),origin.end());
    int pos = len-1;
    while (pos > 0){
        if (nums[pos] > nums[pos-1]){
            pos = pos-1;
            break;
        }
        pos--;
        if (pos==0){
            reverse(nums.begin(), nums.end());
            return nums;
        }
    }
    //cout<<pos<<endl;

    //ascending order exits;
    for (int i = len-1; i > pos; --i){
        if (nums[i] > nums[pos]){
            tmp = nums[i];
            nums[i] = nums[pos];
            nums[pos] = tmp;
            break;
        }
    }
//    for (int i = 0; i < nums.size(); ++i){
//        cout<<nums[i]<<" ";
//    }
    reverse(nums.begin()+pos+1,nums.end());
    return nums;
}
vector<vector<int> > permuteUnique(vector<int>& nums)
{
    vector< vector<int> > res;
    vector< vector<int> > res2;
    int len = nums.size();
    vector<int> origin;
    for (int i = 0; i < len; ++i){
        origin.push_back(i);
    }
    res.push_back(origin);
    vector<int> thisPermute = nextPermutation(origin);
    while (thisPermute!=origin){
        res.push_back(thisPermute);
        thisPermute = nextPermutation(thisPermute);
    }
    vector<int> tmp;
    vector< vector<int> >::iterator iter;
    for (int i = 0; i < res.size(); ++i){
        tmp.clear();
        for (int j = 0; j < res[i].size(); ++j){
            tmp.push_back(nums[res[i][j]]);
        }
        iter = find(res2.begin(), res2.end(), tmp);
        if (iter == res2.end())
            res2.push_back(tmp);
    }
    return res2;
}
int main()
{
    vector<int> nums;
    int n;
    int tmp;
    cin>>n;
    for (int i = 0; i < n; ++i){
        cin>>tmp;
        nums.push_back(tmp);
    }
    vector<vector<int> >res = permuteUnique(nums);
    for (int i = 0; i < res.size(); ++i){
        for (int j = 0; j < res[i].size(); ++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
