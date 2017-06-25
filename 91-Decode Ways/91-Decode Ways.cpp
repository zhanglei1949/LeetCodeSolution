#include<iostream>
#include<vector>
using namespace std;
int num2int(int i, string &s)
{
    int tmp;
    if (i==0) return -1;
    else{
        tmp = 10;
        tmp *= (s[i-1]-'0');
        tmp += (s[i]-'0');
    }
    return tmp;
}
int numDecodings(string s)
{
    int len = s.size();
    if (len==0) return 0;
    if (len==1){
        if (s[0]=='0') return 0;
        return 1;
    }
    int *dp = new int [len+1];
    for (int i = 0; i <= len; ++i) dp[i] = 0;
    dp[0] = 0;
    dp[1] = 1;
    if (s[0]=='0') dp[1] = 0;
    //there is no possibility that there are two 0s.
    for (int i = 1; i < len; ++i){
        int dp_ind = i+1;
        if (num2int(i,s) <= 26 && num2int(i,s) >= 10){
            if (dp_ind==2) dp[dp_ind] = dp[dp_ind-1] + 1;
            else dp[dp_ind] = dp[dp_ind-2] + dp[dp_ind-1];
        }
        else {
            dp[dp_ind] += dp[dp_ind-1];
        }
        if (s[i]=='0') dp[dp_ind] -= dp[dp_ind - 1];
        else if (s[i]=='0' && s[i-1]=='0') dp[dp_ind] = 0;
    }
    for (int i = 0; i <= len; ++i) cout<<dp[i]<<" ";
    cout<<endl;
    return dp[len];
}

int main()
{
    string s;
    cin>>s;
    cout<<numDecodings(s);
}
