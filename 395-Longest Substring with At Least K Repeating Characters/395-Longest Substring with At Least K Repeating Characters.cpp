//time limit execeed
#include<iostream>
#include<vector>
using namespace std;
int longestSubstring(string s, int k)
{
    int maximum = 0;
    //at least k times
    int len = s.size();
    vector< vector< vector<int> > > dp;
    dp.resize(len);

    for (int i = 0; i < len; ++i){
        dp[i].resize(len);
        for (int j = 0; j < len; ++j){
            dp[i][j].resize(26);
            cout<<"initialization"<<endl;
        }
    }
    //dp[i][j] = {a~z}:cnt
    vector<int> cnt(26,0);

    //initialization
    for (int i = 0; i < len; ++i){
        cnt[s[i]-'a'] = 1;
        dp[i][i] = cnt;
        cnt[s[i]-'a'] = 0;
    }
    for (int i = 0; i < len; ++i){
        for (int j = i+1; j < len; ++j){
            vector<int> tmp = dp[i][j-1];
            tmp[s[j]-'a'] += 1;
            dp[i][j] = tmp;
            tmp[s[j]-'a'] -= 1;
        }
    }
    for (int i = 0; i < len; ++i){
        for (int j = i; j < len; ++j){
            cout<<i<<" "<<j<<endl;
            vector<int> tmp = dp[i][j];
            bool flag = true;
            for (int l = 0; l < tmp.size(); ++l){
                if (tmp[l]>0){
                    if (tmp[l] < k){
                        flag = false;
                        break;
                    }
                    //cout<<l<<" "<<tmp[l]<<" ";
                }
            }
            if (flag) maximum = max(maximum, j-i+1);
            //cout<<endl;
        }
    }
    return maximum;
}
int main()
{
    string s = "aaabbbcdefcdefgggggggggggggggcde";
    int k = 3;
    cout<<longestSubstring(s, k);
}
