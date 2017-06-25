#include<iostream>

using namespace std;

bool dfs(string &s1, string &s2, string &s3, int p1, int p2, int p3, int l1, int l2, int l3)
{
    cout<<p1<<" "<<p2<<" "<<p3<<endl;
    if (p1==l1 && p2==l2 && p3==l3) return true;
    if (p1 > l1 || p2 > l2 || p3 > l3) return false;
    if (s1[p1] != s3[p3] && s2[p2] != s3[p3]) return false;
    if (s1[p1] == s3[p3]){
        if (dfs(s1, s2, s3, p1+1, p2, p3+1, l1, l2, l3)){
            return true;
        }
    }
    if (s2[p2] == s3[p3]){
        if (dfs(s1, s2, s3, p1, p2+1, p3+1, l1, l2, l3)){
            return true;
        }
    }
}
bool _isInterleave(string s1, string s2, string s3)
{
    int l1 = s1.size();
    int l2 = s2.size();
    int l3 = s3.size();
    if (l1+l2!=l3) return false;
    //return dfs(s1, s2, s3, 0, 0, 0, l1,l2,l3);
}
bool isInterleave(string s1, string s2, string s3)
{
    int l1 = s1.size();
    int l2 = s2.size();
    int **dp = new int *[l1+1];
    for (int i = 0; i <= l1; ++i){
        dp[i] = new int [l2+1];
        for (int j = 0; j <= l2; ++j)
            dp[i][j] = 0;
    }
    dp[0][0] = 1;
    //dp[i][j] represent whether s1[1:i] with s2[1:j] can form s3[1:i+j] no matter how it forms
    //dp[i][j] = (dp[i-1][j] && s1[i] ==s3[i+j] ) || (dp[i][j-1] && s2[j] == s3[i+j])
    for (int i = 1; i <= l1; ++i){
        dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
    }
    for (int j = 1; j <= l2; ++j){
        dp[0][j] = dp[0][j-1] && s2[j-1] ==s3[j-1];
    }
    for (int i = 1; i <= l1; ++i){
        for (int j = 1; j <= l2; ++j){
            dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
        }
    }
    return dp[l1][l2];
}
int main()
{
    string s1 = "12";
    string s2 = "23";
    string s3 = "1223";
    cout<<isInterleave(s1,s2,s3)<<endl;
    s3 = "415326";
    cout<<isInterleave(s1,s2,s3);
}
