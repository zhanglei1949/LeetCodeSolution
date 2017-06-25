#include<iostream>
#include<algorithm>
using namespace std;


//bool isScramble(string s1, string s2)
//{
//    //cout<<s1<<" "<<s2<<endl;
//    //recursive approach, first check whether s1 and s2 have same characters.
//    //                    then tranverse all possible division
//    if (s1.size()==0) return 1;
//    else if (s1.size()==1) return s1==s2;
//
//    string s11 = s1; string s22 =s2;
//    sort(s11.begin(), s11.end());
//    sort(s22.begin(), s22.end());
//    //cout<<s1<<endl<<s2<<endl;
//
//    for (int i = 0; i < s11.size(); ++i){
//        if (s11[i]!=s22[i]) return false;
//    }
//
//    for (int i = 1; i < s1.size(); ++i){
//        if ((isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)) ) ||
//            (isScramble(s1.substr(0,i), s2.substr(s1.size()-i)) && isScramble(s1.substr(i), s2.substr(0,s1.size()-i))))
//            return true;
//    }
//    return false;
//}
bool isScramble(string s1, string s2)
{
    if (s1.size()==0) return 1;
    else if (s1.size()==1) return s1==s2;

    int length = s1.size();
    int *** dp = new int **[length];
    for (int i = 0; i < length; ++i){
        dp[i] = new int *[length];
        for (int j = 0; j < length; ++j){
            dp[i][j] = new int [length+1];
            for (int k = 0; k <= length; ++k) dp[i][j][k] = 0;
        }
    }
    //initialize
    for (int i = 0; i < length; ++i){
        for (int j = 0; j < length; ++j){
            dp[i][j][1] = (s1[i]==s2[j]);
        }
    }
    //four tier circle
    for (int len = 2; len <= length; ++len){
        for (int i = 0; i <= length-len; ++i){
            for (int j = 0; j <= length-len; ++j){
                for (int k = 1; k < len; ++k){
                    dp[i][j][len] |= ( dp[i][j][k] && dp[i+k][j+k][len-k]) ||
                                        (dp[i][j+len-k][k] && dp[i+k][j][len-k]);
                    if (dp[i][j][len]) break;
                }
            }
        }
    }
    return dp[0][0][length];
}
int main()
{
    string s1, s2;
    cin>>s1>>s2;
    cout<<isScramble(s1, s2);
}
