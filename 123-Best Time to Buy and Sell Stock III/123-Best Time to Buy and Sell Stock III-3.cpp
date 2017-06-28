#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> & prices)
{
    //scan twice, first time calculate maximum profit [0, i]
    //second time calculate maximum profit in [i,len-1]

    //record the minimum up to now
    int len = prices.size();
    vector<int> first(len, 0);
    vector<int> second(len, 0);
    int minimum = prices[0];
    for (int i = 1; i < len; ++i){
        minimum = min(prices[i], minimum);
        first[i] = max(first[i-1], prices[i]-minimum);
    }
    int maximum = prices[len-1];
    for (int i = len-2; i > 0; --i){
        maximum = max(prices[i], maximum);
        second[i] = max(second[i+1], maximum-prices[i]);
    }
    int res = 0;
    for (int i = 0; i < len; ++i){
        res = max(res, first[i]+second[i]);
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
