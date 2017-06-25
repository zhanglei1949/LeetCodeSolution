#include<iostream>

using namespace std;
int min(int a, int b, int c)
{
    return min(a, min(b,c));
}
int minDistance(string word1, string word2)
{
    int len1 = word1.size();
    int len2 = word2.size();
    int **dp = new int *[len1+1];
    for (int i = 0; i <= len1; ++i){
        dp[i] = new int [len2+1];
        for (int j = 0; j <= len2; ++j) dp[i][j] = 0;
    }
    //dp[i][j]: minimum edit distance for word1[1...i], word2[1...j]
    //dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1 : word1[i] != word2[j]
    //         = dp[i-1][j-1] word1[i]==word2[j]
    for (int i = 0; i <= len1; ++i) dp[i][0] = i;
    for (int i = 0; i <= len2; ++i) dp[0][i] = i;
    for (int i = 1; i <= len1; ++i){
        for (int j = 1; j <= len2; ++j){
            if (word1[i-1]==word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])+1;
        }
    }
//    for (int i = 0; i <= len1; ++i){
//        for (int j = 0; j <= len2; ++j)
//            cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }
    return dp[len1][len2];
}
int main()
{
    string word1,word2;
    cin>>word1>>word2;
    cout<<minDistance(word1, word2);

}
