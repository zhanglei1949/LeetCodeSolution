#include<iostream>
#include<vector>
using namespace std;
void dfs(int n, int k, int level,vector<vector<int> > &res,vector<int> &tmp)
{
    if (k==0){
        res.push_back(tmp);
        return ;
    }
    for (int i = level; i <= n-k+1; ++i){
        tmp.push_back(i);
        dfs(n,k-1,i+1,res, tmp);
        tmp.pop_back();
    }
}
vector<vector<int> > combine(int n, int k)
{
    vector<vector<int> > res;
    vector<int> tmp;
    if (k > n) return res;
    if (k==0) return res;
    dfs(n,k,1,res,tmp);
    return res;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int> > res = combine(n,k);
    for (int i = 0; i < res.size(); ++i){
        for (int j = 0; j < res[0].size(); ++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
