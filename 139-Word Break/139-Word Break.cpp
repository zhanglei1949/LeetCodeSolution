#include<iostream>
#include<vector>

using namespace std;

bool wordBreak(string s, vector<string> & wordDict)
{
    int len = s.size();
    int dictSize = wordDict.size();
    vector<bool> dp(len+1,0);
    //dp[i] represent dp[len]
    dp[0] = 1;
    for (int i = 0 ; i <= len; ++i){
        if (!dp[i]) continue;
        for (int j = 0; j < dictSize; ++j){
            if (i+wordDict[j].size() > s.size()) continue;
            string tmp = s.substr(i,wordDict[j].size());
            if (tmp==wordDict[j]) dp[i+wordDict[j].size()] = 1;
        }
    }
    //for (int i = 0; i <= len; ++i) cout<<dp[i]<<" ";
    //cout<<endl;
    return dp[len];

}
int main()
{
    string s = "leetcodeabc";
    vector<string> wordDict = {"leet", "abc", "code"};
    cout<<wordBreak(s, wordDict);
}
