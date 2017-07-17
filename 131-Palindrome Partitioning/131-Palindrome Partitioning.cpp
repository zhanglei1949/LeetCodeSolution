#include<iostream>
#include<vector>

using namespace std;
bool isPalindrome(string s)
{
    for (int i = 0; i < s.size()/2; ++i){
        if (s[i] != s[s.size()-i-1])
            return false;
    }
    return true;
}
void dfs(vector<vector<string>> &res, string &s, vector<string> &cur, int level)
{
    if (level == s.size()){
        res.push_back(cur);
        return ;
    }
    for (int i = level; i < s.size(); ++i){
        string sub = s.substr(level, i-level+1);
        if (isPalindrome(sub)){
            cur.push_back(sub);
            dfs(res, s, cur, i+1);
            cur.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> cur;
    dfs(res, s, cur, 0);
    return res;
}
int main()
{
    string s = "12121";
    vector<vector<string>> res = partition(s);
    for (int i = 0 ; i < res.size(); ++i){
        for (int j = 0; j < res[i].size(); ++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
