#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void print(vector<vector<int> > layer)
{
    int len = layer.size();
    for (int i = 0; i < len; ++i){
        for (int j = 0; j < layer[i].size(); ++j){
            cout<<layer[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
vector<vector<int> > subsetsWithDup(vector<int>& nums)
{
    //similar to gray code, iteratively add items into vectors
    // 1. []
    // 2. [], [1]
    // 3. [], [1],[2], [1,2]
    // 4. [], [1], [2], [1,2], [2,2], [1,2,2]
    int len = nums.size();
    vector<vector<int> > res;
    sort(nums.begin(), nums.end());
    vector<vector<int> > this_layer;
    vector<vector<int> > this_layer_tmp;
    vector<int> a;
    res.push_back(a);
    for (int i = 0; i < len; ++i){
        cout<<res.empty()<<endl;
        cout<<"i"<<i<<endl;
        this_layer_tmp.clear();
        if (i > 0 && nums[i] == nums[i-1]){
            for (int j = 0; j < this_layer.size(); ++j){
                vector<int> cur = this_layer[j];
                cur.push_back(nums[i]);
                this_layer_tmp.push_back(cur);
                res.push_back(cur);
            }
            this_layer = this_layer_tmp;
        }
        else {
            if (res.size()==1){
                vector<int> tem;
                tem.push_back(nums[i]);
                this_layer_tmp.push_back(tem);
                res.push_back(tem);
            }
            else {
                for (int j = 0; j < res.size(); ++j){
                    vector<int> cur = res[j];
                    cur.push_back((nums[i]));
                    this_layer_tmp.push_back(cur);
                    res.push_back(cur);
                }
            }
            this_layer = this_layer_tmp;
        }
        print(this_layer);
        //print(this_layer_tmp);
    }
    return res;
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    //nums.push_back(3);
    //nums.push_back(3);
    //nums.push_back(3);
    vector<vector<int> > res = subsetsWithDup(nums);
    for (int i = 0; i < res.size(); ++i){
        for (int j = 0; j < res[i].size(); ++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
