#include<iostream>
#include<vector>

using namespace std;

//this time we have to return the solution
void dfs(int level, string &s, vector<string> & wordDict, vector<string> &cur, vector<vector<string>> & record)
{
    //for (int i = 0; i < cur.size(); ++i) cout<<cur[i]<<" ";
    //cout<<endl;
    if (level == s.size()){
        record.push_back(cur);
        return ;
    }
    for (int i = 0; i < wordDict.size(); ++i){
        if (level + wordDict[i].size() > s.size()) continue;
        string tmp = s.substr(level, wordDict[i].size());
        if (tmp == wordDict[i]){
            cur.push_back(tmp);
            dfs(level+tmp.size(), s, wordDict, cur, record);
            cur.pop_back();
        }
    }
}
vector<string> wordBreak(string s, vector<string>& wordDict)
{
    vector<string>  res;// we will return
    vector<vector<string>> record;// we remember the solutions
    vector<string> cur;
    int len = s.size();
    int dictSize = wordDict.size();

    dfs(0, s, wordDict, cur, record);
    //fill in
    for (int i = 0; i < record.size(); ++i){
        string s;
        for (int j = 0; j < record[i].size()-1; ++j){
            s += record[i][j];
            s += " ";
        }
        s+=record[i][record[i].size()-1];
        res.push_back(s);
    }
    return res;
}
int main()
{
//    string s = "catsanddog";
    string s = "aaaaaaaa";
 //   vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> wordDict = {"a","aa","aaa","aaaa"};

    vector<string> res = wordBreak(s, wordDict);
    for (int i = 0; i < res.size(); ++i){
        cout<<res[i]<<endl;
    }
}
