#include<iostream>
#include<vector>
using namespace std;

vector<int> graycode(int n)
{
    vector<int> res;
    res.push_back(0);
    for (int i = 0; i < n; ++i){
        int s = res.size();
        while (s){
            s--;
            int cur = res[s];
            cur += (1<<i);
            res.push_back(cur);
        }
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    vector<int> res = graycode(n);
    for (int i = 0; i < res.size(); ++i){
        cout<<res[i]<<" ";
    }
}
