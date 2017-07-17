#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
forwarding??
*/
//this time we have to return the solution
vector<vector<string> >  dfs(string s, vector<string> & wordDict, map<string, vector<vector<string> > > & m)
{
    //cout<<s<<endl;
    //find all the possible solutions for string s and return them in vector<vector<string>>
    vector<vector<string> > res;
    if (m[s].size()){
        cout<<s<<" has been visited"<<endl;
//        cout<<"___________________________"<<endl;
//        for (int i = 0; i < m[s].size(); ++i){
//            for (int j = 0; j < m[s][i].size(); ++j){
//                cout<<m[s][i][j]<<" ";
//            }
//            cout<<endl;
//        }
//        cout<<"___________________________"<<endl;
        return m[s];

    }
    for (int i = 0; i < wordDict.size(); ++i){
        if (s.size() > wordDict[i].size()){
            string match = s.substr(s.size() - wordDict[i].size());
            if ( match == wordDict[i]){
                //cout<<s.substr(0, wordDict[i].size())<<"=="<<wordDict[i]<<endl;
                vector<vector<string> > tmp = dfs(s.substr(0, s.size() - wordDict[i].size()), wordDict, m);
                for (int j = 0; j < tmp.size(); ++j){
                    tmp[j].push_back(match);
                    res.push_back(tmp[j]);
                }
            }
        }
        else if (s.size()==wordDict[i].size()){
            if (s.substr(0, wordDict[i].size()) == wordDict[i]){
                vector<string> tmp;
                tmp.push_back(s);
                res.push_back(tmp);
            }
        }
    }
    m[s] = res;
    return res;
}
vector<string> wordBreak(string s, vector<string>& wordDict)
{
    vector<string>  res;// we will return

    vector<string> cur;
    map<string, vector<vector<string> > > m;
    int len = s.size();
    int dictSize = wordDict.size();

    vector<vector<string> > record = dfs(s, wordDict, m);
    //fill in
    for (int i = 0; i < record.size(); ++i){
        string s;
        for (int j = 0 ; j < record[i].size()-1; ++j){
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
    //string s = "aaaaaaaa";
    string s = "catsandog";
    //cout<<s.substr(1);
    vector<string> wordDict;
    wordDict.push_back("cat");
    wordDict.push_back("cats");
    wordDict.push_back("and");
    wordDict.push_back("sand");
    wordDict.push_back("og");

//    vector<string> wordDict = {"a","aa","aaa","aaaa"};

//    wordDict.push_back("a");
//    wordDict.push_back("aa");
//    wordDict.push_back("aaa");
//    wordDict.push_back("aaaa");


    vector<string> res = wordBreak(s, wordDict);
    for (int i = 0; i < res.size(); ++i){
        cout<<res[i]<<endl;
    }
}
