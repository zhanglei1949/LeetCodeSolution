#include<iostream>
#include<vector>
using namespace std;
int str2int(string s)
{
    int res = 0;
    if (s=="0") return 0;
    for (int i = 0; i < s.size(); ++i){
        res = res*10 + (s[i]-'0');
        if (res==0) return 256;
    }
    return res;
}
void dfs(vector<string> & res, vector<int> & cur, string &s, int need, int level, int len)
//start from index level.
//the dot is after cur[i]
{
    //cout<<"level: "<<level<<" need: "<<need<<" cur size:"<<cur.size()<<endl;
    if (level > len)
        return ;
    if (need == 0 && level < len){
        return ;
    }
    if (level == len && need == 0){
        string tmp = s;
        for (int i = cur.size()-2; i >= 0; --i){
            //cout<<cur[i]<<" ";
            tmp.insert(cur[i],".");
        }
        //cout<<tmp<<endl;
        res.push_back(tmp);
        return ;
    }
    for (int i = 0; i <= min(2, len-level-1); ++i){
        string tmp = s.substr(level,i+1);
        int num = str2int(tmp);
        //cout<<tmp<<" "<<num<<endl;
        if (num > 255){
            continue;
        }
        else {
            cur.push_back(level+i+1);
            dfs(res, cur, s, need - 1, level+i+1, len);
            cur.pop_back();
        }
    }
}
vector<string> restoreIpAddresses(string s)
{
    vector<string> res;
    vector<int> cur;
    int len = s.size();

    if (len > 12 || len < 4) return res;
    int need = 4;
    int level = 0;
    dfs(res, cur, s, need, level,len);
    return res;
}
int main()
{
    string s;
    cin>>s;
    vector<string> res = restoreIpAddresses(s);
    cout<<res.size()<<endl;
    for (int i = 0; i < res.size(); ++i){
        cout<<res[i]<<endl;
    }
}
