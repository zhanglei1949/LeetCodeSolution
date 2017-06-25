#include<iostream>
using namespace std;
int numTrees_(int n)
{
    int **dp = new int *[n];
    for (int i = 0; i < n; ++i){
        dp[i] = new int [n];
        for (int j = 0; j < n; ++j){
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i) dp[i][i] = 1;
    for (int len = 1; len < n; ++len){
        for (int i = 0; i < n-len; ++i){
            dp[i][i+len] += dp[i+1][i+len];
            dp[i][i+len] += dp[i][i+len-1];
            for (int j = i+1; j < i+len; ++j){
                dp[i][i+len] += dp[i][j-1]*dp[j+1][i+len];
            }
        }
    }
//    for (int i = 0; i < n; ++i){
//        for (int j = 0; j < n; ++j){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return dp[0][n-1];
}
/*
In fact the left side and the right side has no difference with order.
*/
int numTrees(int n)
{
    int *dp = new int [n+1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n; ++i) dp[i] = 0;
    for (int i = 2; i <= n; ++i){
        for (int j = 1; j <= i; ++j){
            dp[i] += dp[j-1]*dp[i-j];
        }
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<numTrees(n);
}
