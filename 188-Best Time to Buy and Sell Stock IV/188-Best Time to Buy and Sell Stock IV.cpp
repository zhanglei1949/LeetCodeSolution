#include<iostream>
#include<vector>
using namespace std;
int _maxProfit(int k, vector<int>& prices)
{
    int len = prices.size();
    vector<vector<int>> dp(k+1, vector<int> (len+1, 0));
    //dp[i][j] represent the best profit from [0,j], i.e. [0.j-1] using at most i transactions
    //result is dp[k][len]
    //dp[i][j] = max(dp[i-1][j], dp[i-1][k]+prices[j]-prices[k+1]);
    //initialization
    for (int i = 0; i < k+1; ++i){
        dp[i][0] = 0;
    }
    for (int j = 0; j < len+1; ++j){
        dp[0][j] = 0;
    }
    for (int i = 1; i < k+1; ++i){
        for (int j = 1; j < len+1; ++j){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            for (int l = 0; l < j; ++l){
                dp[i][j] = max(dp[i][j], dp[i-1][l]+prices[j-1] - prices[l]);
            }
        }
    }
//    for (int i = 0; i <= k; ++i){
//        for (int j = 0; j < len+1; ++j){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return dp[k][len];
}
int maxProfit(int k, vector<int>& prices)
{
    //can we use only two rows?
    int len = prices.size();
    //important observation, if k > n/2, then we can make as much transactions as we can
    if (k >= len/2){
        int res = 0;
        for (int i = 1; i < len; ++i){
            if (prices[i] > prices[i-1]) res+=prices[i] - prices[i-1];
        }
        return res;
    }
    vector<vector<int>> dp(2, vector<int> (len+1, 0));
    //dp[i][j] represent the best profit from [0,j], i.e. [0.j-1] using at most i transactions
    //result is dp[k][len]
    //dp[i][j] = max(dp[i-1][j], dp[i-1][k]+prices[j]-prices[k+1]);
    //initialization
    for (int i = 0; i < 2; ++i){
        dp[i][0] = 0;
    }
    for (int j = 0; j < len+1; ++j){
        dp[0][j] = 0;
    }
    for (int ii = 1; ii < k+1; ++ii){
        int i = ii%2;
        for (int j = 1; j < len+1; ++j){
            dp[i][j] = max(dp[(i+1)%2][j], dp[i][j-1]);
            for (int l = 0; l < j; ++l){
                dp[i][j] = max(dp[i][j], dp[(i+1)%2][l]+prices[j-1] - prices[l]);
            }
        }
    }
//    for (int i = 0; i <= k; ++i){
//        for (int j = 0; j < len+1; ++j){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return dp[k%2][len];
}
int main()
{
    vector<int> prices = {1,2,6,4,5};
    cout<<maxProfit(3,prices);
}
