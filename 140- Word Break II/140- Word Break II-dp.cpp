#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> wordBreak_dp(string s, vector<string> & wordDict)
{
    int len = s.size();
    int dictSize = wordDict.size();
    vector<int> dp(len+1,0);
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
    return dp;
}
vector<string> wordBreak(string s, vector<string>& wordDict)
{
    vector<string>  res;// we will return
    map<int, vector<vector<string>> > m;

    int len = s.size();
    int dictSize = wordDict.size();

    vector<int> dp = wordBreak_dp(s, wordDict);
    //dp solution
    //dp[i] = dp[i-dictionary[j].size()].push_back(dictionary[j])
    //have to store
    m[0] = {{}};
    for (int i = 0; i <= len; ++i){
        //actually m[1]
        if (dp[i]){
            for (int j = 0; j < dictSize; ++j){
                if (i + wordDict[j].size() > len) continue;
                string tmp = s.substr(i, wordDict[j].size());
                if (tmp == wordDict[j]){
                    for (int k = 0; k < m[i].size(); ++k){
                        vector<string> cur_one = m[i][k];
                        cur_one.push_back(tmp);
                        m[i+wordDict[j].size()].push_back(cur_one);
                    }
                    dp[i+wordDict[j].size()] = 1;
                }
            }
        }
    }
//    for (int i = 0; i <= len; ++i){
//        cout<<dp[i]<<" ";
//    }
//    cout<<endl;
    for (int i = 0; i < m[len].size(); ++i){
        string s;
        for (int j = 0; j < m[len][i].size()-1; ++j){
            s += m[len][i][j];
            s += " ";
        }
        s+=m[len][i][m[len][i].size()-1];
        res.push_back(s);
    }
    return res;
}
int main()
{
    string s = "catsanddog";
    //string s = "aaaaaaaa";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
 //   vector<string> wordDict = {"a","aa","aaa","aaaa"};

    vector<string> res = wordBreak(s, wordDict);
    for (int i = 0; i < res.size(); ++i){
        cout<<res[i]<<endl;
    }
}
