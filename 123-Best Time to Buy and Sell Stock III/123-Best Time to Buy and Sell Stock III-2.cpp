#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> & prices)
{
    //scan twice, first time calculate maximum profit [0, i]
    //second time calculate maximum profit in [i,len-1]
    int len = prices.size();
    vector<int> first(len, 0);
    vector<int> second(len, 0);
    vector<vector<int> > dp(len, vector<int>(len,0));
    for (int i = 0; i < len; ++i){
        for (int j = i+1; j < len; ++j){
            dp[i][j] = max(0, dp[i][j-1] + prices[j]-prices[j-1]);
        }
    }
    //dp[i] represent until i-th
    for (int i = 1; i < len; ++i){
        //first[i] = max(first[i], dp[j][k]);
        first[i] = first[i-1];
        for (int j = 0; j <= i; ++j){
            for (int k = j; k <= i; ++k){

                first[i] = max(first[i], dp[j][k]);
            }
        }
    }
    for (int i = len-2; i >= 0; --i){
        //first[i] = max(first[i], dp[j][k]);
        second[i] = second[i+1];
        for (int j = i; j < len; ++j){
            for (int k = j; k < len; ++k){
                second[i] = max(second[i], dp[j][k]);
            }
        }
    }
//    for (int i = 0; i < len; ++i) cout<<first[i]<<" ";
//    cout<<endl;
//    for (int i = 0; i < len; ++i) cout<<second[i]<<" ";
//    cout<<endl;
    int res = 0;
    for (int i = 0; i < len; ++i){
        res = max(res, first[i] + second[i]);
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
