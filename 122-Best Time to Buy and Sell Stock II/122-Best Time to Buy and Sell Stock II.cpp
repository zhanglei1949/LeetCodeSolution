#include<iostream>
#include<vector>
using namespace std;
int _maxProfit(vector<int>& prices) {
    int len = prices.size();
    vector<int> dp(len, 0);
    for (int i = 1; i < len; ++i){
        dp[i] = dp[i-1];
        for (int j = 0; j < i; ++j){
            dp[i] = max(dp[i], dp[j]+prices[i]-prices[j]);
        }
    }
    for (int i = 0; i < len; ++i) cout<<dp[i]<<" ";
    cout<<endl;
    return dp[len-1];
}
int __maxProfit(vector<int> &prices)
{
    //stupid
    int in = 0;
    int out = 0;
    int maximum = 0;
    int len = prices.size();
    vector<int> v;
    for (int i = 0; i < len; ++i){
        //for (int j = 0; j < v.size(); ++j) cout<<v[j]<<" ";
        //cout<<endl;
        if (v.size() == 0 || v[v.size()-1] < prices[i]){
            v.push_back(prices[i]);
        }
        else {
            if (v.size() > 0){
                maximum += v[v.size()-1] - v[0];
                v.clear();
                v.push_back(prices[i]);
            }
        }
    }
    if (v.size() > 0){
        maximum += v[v.size()-1] - v[0];
    }
    return maximum;
}
int maxProfit(vector<int> &prices)
{
    int res = 0;
    for (int i = 0; i < prices.size()-1; ++i){
        if (prices[i+1] > prices[i]) res+=prices[i+1] - prices[i];
    }
    return res;
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
