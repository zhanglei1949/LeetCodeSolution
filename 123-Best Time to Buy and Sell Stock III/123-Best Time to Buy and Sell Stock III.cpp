#include<iostream>
#include<vector>
using namespace std;

int maxProfit_(vector<int>& prices)
{
    //TLE
    int len = prices.size();
    int **dp = new int *[len];
    for (int i = 0; i < len; ++i){
        dp[i] = new int [len];
    }
    //dp[i][j] is the maximum profit from [i, j]
    //res = max(dp[i][k],dp[k+1][j])
    for (int i = 0; i < len; ++i){
        for (int j = 0; j < len; ++j)
            dp[i][j] = 0;
    }
    for (int l = 1; l < len; ++l){
        for (int i = 0; i < len-l; ++i){
            dp[i][i+l] = max(0, dp[i][i+l-1] + prices[i+l] - prices[i+l-1]);
        }
    }
    for (int i = 0; i < len; ++i){
        for (int j = 0; j < len; ++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int res = 0;
    for (int i = 0; i < len-1; ++i){
        for (int j = 1; j < len; ++j)
            for (int k = i; k < j; ++k)
            res = max(res, dp[i][k]+dp[k][j]);
    }
    return res;
}
int maxProfit__(vector<int> &prices)
{
    //dp[k][len] represent using k transaction, the maximum profit we can get until <len>
    //dp[k][i] = max(dp[k-1][j]+ prices[i] - prices[j]), j in (0, i)
    //initialization: dp[0][i] = 0, dp[k][0] = 0
    int k = 2;
    int len = prices.size();
    vector<vector<int> > dp(k+1, vector<int> (len, 0));
    for (int i = 1; i <= k; ++i){
        for (int j = 1; j < len; ++j){
            for (int l = 0; l <= j; ++l){
                dp[i][j] = max(dp[i][j], max(dp[i][j-1], dp[i-1][l] + prices[j] - prices[l]));
            }
        }
    }
//    for (int i = 0; i <= k; ++i){
//        for (int j = 0; j < len; ++j){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return dp[k][len-1];

}
int maxProfit(vector<int> & prices)
{
    int K = 2;
    int maxProf = 0;
    int len = prices.size();
    vector<vector<int> > f(K+1, vector<int>(len, 0));
    for (int k = 1; k <= K; k++) {
        int tmpMax = f[k-1][0] - prices[0];
        for (int i = 1; i < prices.size(); i++) {
            f[k][i] = max(f[k][i-1], prices[i] + tmpMax);
            tmpMax = max(tmpMax, f[k-1][i] - prices[i]);
            maxProf = max(f[k][i], maxProf);
            }
        }
    return maxProf;
}
int main()
{
    vector<int> prices;
    prices.push_back(0);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(2);
    prices.push_back(6);
    prices.push_back(4);
    cout<<maxProfit(prices);
}
