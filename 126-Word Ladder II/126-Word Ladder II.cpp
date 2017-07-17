#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int cal_dif(string &a, string &b)
{
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i){
        if (a[i]!=b[i]) ++cnt;
    }
    //cout<<a<<" "<<b<<" "<<cnt<<endl;
    return cnt;
}
void search_(vector<vector<int>> &transition, vector<vector<int>> &res, vector<int> &flag, stack<int> &s, int cur, int end, int &minimum_len, int & cur_dep)
{
    if (cur_dep + 1 > minimum_len) return ;
    //cur is not performed;
    if (cur==end){
        vector<int> tmp;
        s.push(cur);
        while (!s.empty()){
            tmp.push_back(s.top());
            s.pop();
        }
        res.push_back(tmp);
//        for (int i = 0; i < tmp.size(); ++i){
//            cout<<tmp[i]<<" ";
//        }
//        cout<<endl;
        //now the stack is empty, we have to recover
        for (int i = tmp.size()-1; i > 0; --i){
            s.push(tmp[i]);
        }
        minimum_len = min(minimum_len, int(tmp.size()));

        return ;
    }
    s.push(cur);
    flag[cur] = 1;
    cur_dep+=1;
    for (int i = 0; i < transition[cur].size(); ++i){
        if (flag[i]) continue;
        if (transition[cur][i] == 1){
            search_(transition, res, flag, s, i, end, minimum_len, cur_dep);
        }
    }
    s.pop();
    flag[cur] = 0;
    cur_dep -= 1;
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
{
    //return all the transformation sequences
    //1. first build the transition matrix
    //2. then do the maze search back tracking using stack

    vector<vector<int>> res;
    vector<vector<string>> res1;
    int len = wordList.size();
    if (len == 0) return res1;
    vector<vector<int>> transition(len , vector<int> (len, 0));
    for (int i = 0; i < len; ++i) transition[i][i] = 0;
    for (int i = 0; i < len; ++i){
        for (int j = i+1; j < len; ++j){
            //calculate the difference, i.e. the number of characters that are different
            transition[i][j] = transition[j][i] = cal_dif(wordList[i], wordList[j]);
        }
    }
//    for (int i = 0; i < len; ++i){
//        for (int j = 0; j < len; ++j){
//            cout<<transition[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    int end = -1;
    //search, start from begin word
    for (int i = 0; i < len; ++i){
        if (wordList[i]==endWord){
            end = i;
            break;
        }
    }
    //cout<<end<<endl;
    int minimum_len = len;
    for (int i = 0; i < len; ++i){
        if (cal_dif(beginWord, wordList[i])==1){
            //search
            vector<int> flag(len, 0);
            stack<int> s;
            int cur_dep = 0;
            search_(transition, res, flag, s, i, end, minimum_len, cur_dep);
        }
    }
    //cout<<minimum_len<<endl;
    for (int i = 0; i < res.size(); ++i){
        if (res[i].size()!=minimum_len) continue;
        vector<string> tmp;
        tmp.push_back(beginWord);
        for (int j = 0; j < res[i].size(); ++j){
            // reverse order
            tmp.push_back(wordList[res[i][res[i].size()-j-1]]);
        }
        res1.push_back(tmp);
    }
    return res1;

}
int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> res= findLadders(beginWord, endWord, wordList);
    for (int i = 0; i < res.size(); ++i){
        for (int j = 0; j < res[i].size(); ++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
