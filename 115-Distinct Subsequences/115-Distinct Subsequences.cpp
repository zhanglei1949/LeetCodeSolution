//time limit exceed
#include<iostream>

using namespace std;
int min(int a, int b)
{
    if (a < b) return a;
    return b;
}
void numDistinct(string &s, string &t, int ss, int ts, int red, int &res)
{
    cout<<ss<<" "<<ts<<" "<<red<<endl;
    if (ts==t.size() && ss+red==s.size()){
        cout<<"res+=1"<<endl;
        res+=1;
        return ;
    }
    for (int i = ss; i < min(ss+red+1, s.size() ); ++i){
        if (s[i] == t[ts]) numDistinct(s, t, i+1, ts+1, red-(i-ss), res);
    }
}
int numDistinct(string s, string t)
{
    int res = 0;
    numDistinct(s,t,0,0, s.size()-t.size(), res);
    return res;
}
int main()
{
    string s = "123123";
    string t = "123";
    cout<<numDistinct(s,t);
    //cout<<s.size()<<endl;
}
