#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;
    vector<int> cur;
    //first line
    cur.push_back(1);
    res.push_back(cur);
    for (int i = 1; i < numRows; ++i){
        cur.clear();
        cur.push_back(1);
        for (int j = 1; j < i; ++j){
            cur.push_back(res[i-1][j-1] + res[i-1][j]);
        }
        cur.push_back(1);
        res.push_back(cur);
    }
    return res;
}
int main()
{
    int numRows = 5;
    vector<vector<int>> res = generate(numRows);
    for (int i = 0; i < res.size(); ++i){
        for (int j = 0; j < res[i].size(); ++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
