#include<iostream>

using namespace std;

long long climbStairs(int n)
{
    long long *dp = new int [n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<climbStairs(n);
}
