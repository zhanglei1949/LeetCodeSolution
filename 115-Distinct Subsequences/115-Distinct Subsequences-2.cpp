//time limit exceed
#include<iostream>

using namespace std;

int numDistinct(string s, string t)
{
    //dp
    //result is dp[s.size()][t.size()]
    //dp[0][1~t.size()] = 0
    //dp[1~s.size()][0] = 1
    //if s[i]==t[j], dp[i][j] = dp[i-1][j-1](using this character) + dp[i-1][j](do not use)
    //if s[i]!=t[j], dp[i][j] = dp[i-1][j]
    int **dp = new int * [s.size()+1];
    //note the order of initialization
    for (int i = 0; i < s.size()+1; ++i) dp[i] = new int [t.size()+1];
    for (int i = 0; i < t.size()+1; ++i) dp[0][i] = 0;
    for (int i = 0; i < s.size()+1; ++i) dp[i][0] = 1;

    for (int i = 1; i < s.size()+1; ++i){
        for (int j = 1; j < t.size()+1; ++j){
            if (s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    for (int i = 0; i < s.size()+1; ++i){
        for (int j = 0; j < t.size()+1; ++j)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[s.size()][t.size()];
}
int main()
{
    string s = "2";
    string t = "1";
    cout<<numDistinct(s,t);
    //cout<<s.size()<<endl;
}
