#include<iostream>
#include<vector>
using namespace std;
int maxProfit_(vector<int>& prices)
{
    //not dp solution
    int maximum = 0;
        if (prices.size()==0) return 0;
        int in = prices[0];
        int out = prices[0];
        for (int i = 1; i < prices.size(); ++i){
            bool flag = false;
            if (prices[i] < in){
                in = prices[i];
                out = prices[i];
                flag = true;
            }
            else if (prices[i] > out){
                out = prices[i];
                flag = true;
            }
            if (flag) maximum = max(maximum, out-in);

        }
        return maximum;
}
int maxProfit(vector<int> & prices)
{
    //dp solution, similar to maximum subarray
    int maxCur = 0;
    int maximum = 0;
    //cout<<maxCur<<" ";
    for (int i = 1; i < prices.size(); ++i){
        maxCur = max(0, maxCur + prices[i]-prices[i-1]);
        maximum = max(maximum, maxCur);
        //cout<<maxCur<<" ";
    }
    return maximum;
}
int main()
{
    vector<int> prices;
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);
    cout<<maxProfit(prices);
}
