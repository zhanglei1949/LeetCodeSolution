#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int largestRectangleArea(vector<int> &heights)
{
    int res = 0;
    stack<int> s;
    int len = heights.size();
    if (len==0) return 0;
    for (int i = 0; i < len; ++i){
        if (s.empty() || heights[s.top()] <= heights[i]){
            s.push(i);
        }
        else {
            int poped = heights[s.top()];
            s.pop();
            int cur = 0;
            if (s.empty()){
                cur = poped*(i);
                //from 0 to i-1, all big than poped
            }
            else cur = poped*(i-s.top()-1);
            // s.top()+1 -> i
            res = max(res, cur);
            i--;
        }
    }
    while (!s.empty()){
        int poped = heights[s.top()];
        s.pop();
        res = max(res, poped*(s.empty() ? len : len - s.top()-1));
    }
    return res;
}
int largestRectangleArea__(vector<int> &heights)
{
    //TLE
    int res = 0;
    int len = heights.size();
    //int *left = new int [len];
    //int *right = new int [len];
    int j;
    int left,right;
    for (int i = 0; i < len; ++i){
        j = i;
        while (j >= 0 && heights[j] >= heights[i]){
            j--;
        }
        left = i-j;
        j = i;
        while (j < len && heights[j] >= heights[i]){
            j++;
        }
        right = j-i-1;
        //cout<<left<<" "<<right<<" "<<heights[i]<<endl;
        res = max(res, heights[i]*(left+right));
    }
    return res;
}
int largestRectangleArea_(vector<int>& heights)
{
    //TLE
    int res = 0;
    int len = heights.size();
    if (len==0) return 0;
    int **dp = new int *[len];
    for (int i = 0; i < len; ++i){
        dp[i] = new int [len];
        for (int j = 0; j < len; ++j){
            dp[i][j] = 0;
        }
    }
    //dp[i][j] = heights[i]->[j] minimum heights
    //dp[i][j]=min(dp[i][j-1], heights[j])
    res=heights[0];
    for (int i = 0; i < len; ++i){
        dp[i][i] = heights[i];
        res = max(res, heights[i]);
    }
    for (int i = 0; i < len; ++i){
        for (int j = i+1; j < len; j++){
            dp[i][j] = min(dp[i][j-1], heights[j]);
            res = max(res, dp[i][j]*(j-i+1));
        }
    }
    return res;
}
int main()
{
    vector<int> heights;
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(5);
    heights.push_back(6);
    heights.push_back(2);
    heights.push_back(3);
    cout<<largestRectangleArea(heights);
}
