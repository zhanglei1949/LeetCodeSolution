#include<iostream>
#include<vector>
#include<map>
using namespace std;

string minWindow(string s, string t)
{
    map<char, int> m;
    int left,right;
    int left_res = 0;
    int right_res = 0;
    int res = 99999999;
    int flag = 0;
    left = 0; right = 0;
    while (right < s.size()){
        if (t.find(s[right]) < t.size()){
            if (!flag){
                left = right;
                flag = 1;
            }
            m[s[right]] += 1;
        }
        int i = 0;
        for (i = 0; i < t.size(); ++i){
            if (!m[t[i]]) break;
        }
        if (i==t.size()) break;
        right++;
    }
    //find the first interval
    if (right==s.size()) return "";
    cout<<s.substr(left, right-left+1)<<endl;
    while (right < s.size()){
        //pop a left, push a right;
        cout<<s.substr(left, right-left+1)<<endl;
        while (t.find(s[left]) >= t.size()){
            left++;
        }
        char c = s[left];
        left++;
        while (t.find(s[left]) >= t.size()|| s[left]==c){
            if (s[left]==c){
                if (m[s[left]]){
                    m[s[left]]-=1;
                }
            }
            left++;
        }
        while (right < s.size()){
            if (s[right]!=c) right++;
            else break;
        }
        if (right==s.size()) break;
        if (right - res < res){
            left_res = left;
            right_res = right;
            res = right - left;
        }
    }
    return s.substr(left_res, right_res-left_res+1);
}
int main()
{
    string s, t;
    cin>>s>>t;
    cout<<minWindow(s,t);
}
/*
ADOBECODEBANC
ABC
*/
