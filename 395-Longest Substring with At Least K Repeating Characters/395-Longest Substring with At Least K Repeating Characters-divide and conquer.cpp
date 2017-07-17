//time limit execeed
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<char, int> m;
int longestSubstring(string s, int k)
{
    if (k==0) return s.size();
    if (k > s.size()) return 0;
    if (s.size()==0) return 0;
    m.clear();
    for (int i = 0; i < s.size(); ++i){
        m[s[i]]++;
    }
    //find the first character which can never be included in a  qualified substring
    int pos = 0;
    while (pos < s.size() && m[s[pos]] >= k){
        pos++;
    };
    if (pos==s.size()) return s.size();
    return max(longestSubstring(s.substr(0,pos), k),
                   longestSubstring(s.substr(pos+1), k));
}
int main()
{
    string s = "aaabbbcdefcdefgggggggggggggggcde";
    int k = 3;
    cout<<longestSubstring(s, k);
}
