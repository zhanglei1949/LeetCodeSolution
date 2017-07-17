#include<iostream>
#include<vector>
using namespace std;
int findCircleNum(vector<vector<int>>& M)
{
    int n = M.size();
    vector<int> father(n, 0);
    for (int i = 0 ; i < n; ++i){
        father[i] = i;
    }
    for (int i = 0; i < n; ++i){
        for (int j = i+1; j < n; ++j){
            if (M[i][j]==1){
                //i and j are friends
                if (father[i]==i && father[j] == j) father[j] = i;
                else if (father[i] != i && father[j] != j){
                    if (father[i]==father[j]) continue;
                    int cur = j;
                    while (father[cur] != cur){
                        cur = father[cur];
                    }
                    //get to the root;
                    father[cur] = i;
                }
                else if (father[i]!=i) father[j] = i;
                else father[i] = j;
            }
        }
    }
    for (int i = 0; i < n; ++i) cout<<father[i]<<" ";
    cout<<endl;
    int cnt = 0;
    for (int i = 0; i < n; ++i) if (father[i]==i) cnt++;
    return cnt;
}
int main()
{
    //vector<vector<int>> m={{1,0,0,1}, {0,1,1,0}, {0,1,1,1}, {1,0,1,1}};
    vector<vector<int>> m={{1,1,1}, {1,1,1}, {1,1,1}};
    cout<<findCircleNum(m);
}
