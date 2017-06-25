#include<iostream>

using namespace std;

void dfs(int n, int &res)
{
    if (n==0){
        ++res;
        return ;
    }
    if (n<0) return ;
    dfs(n-1, res);
    dfs(n-2, res);
}
int climbStairs(int n)
{
    int res = 0;
    dfs(n, res);
    return res;
}
int main()
{
    int n;
    cin>>n;
    cout<<climbStairs(n);
}
