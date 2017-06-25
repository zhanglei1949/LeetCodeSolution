#include<iostream>
#include<vector>
using namespace std;

int minPathSum(vector<vector<int> >& grid)
{
    if (grid.size()==0) return 0;
    int res = 0;
    int m = grid.size();
    int n = grid[0].size();
    int **dp = new int *[m];
    for (int i = 0; i < m; ++i){
        dp[i] = new int [n];
    }
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; ++i) dp[i][0] = grid[i][0]+dp[i-1][0];
    for (int i = 1; i < n; ++i) dp[0][i] = grid[0][i]+dp[0][i-1];
    for (int i = 1; i < m; ++i){
        for (int j = 1; j < n; ++j){
            dp[i][j] = min(dp[i-1][j], dp[i][j-1])+grid[i][j];
        }
    }
    return dp[m-1][n-1];
}
int main()
{
    vector<vector<int> > grid;
    vector<int> row(3,1);
    row[2] = 3;
    grid.push_back(row);
    row[0] = 2;
    row[2] = 0;
    row[1] = 5;
    grid.push_back(row);
    row[1] = 4;
    row[0] = 5;
    grid.push_back(row);
    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[0].size(); ++j)
            cout<<grid[i][j]<<" ";
        cout<<endl;
    }
    cout<<minPathSum(grid);
}
