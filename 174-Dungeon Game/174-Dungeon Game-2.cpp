#include<iostream>
#include<vector>
#include<queue>
//what fuck
using namespace std;
struct point
{
    int x;
    int y;
    int dir;// 0 for right, 1 for down
    int cost;
    int min_cost;
    point(int xx = 0, int yy = 0, int dirr = 0,int c = 0):x(xx), y(yy), dir(dirr),cost(c), min_cost(min(0, c)) {}
};
int calculateMinimumHP(vector<vector<int>>& dungeon)
{
    int rows = dungeon.size();
    int cols = dungeon[0].size();
    vector<vector<int>> hp(rows, vector<int> (cols, 0));
    vector<vector<int>> previous(rows, vector<int> (cols, 0));
    hp[0][0] = dungeon[0][0];
    previous[0][0] = min(0,dungeon[0][0]);
    //also have to record the local minimum along the path
    for (int i = 1; i < rows; ++i){
        //hp[i][0] = min(0, min(hp[i-1][0]+dungeon[i][0], hp[i-1][0]));
        hp[i][0] = hp[i-1][0]+dungeon[i][0];
        previous[i][0] = min(hp[i][0], previous[i-1][0]);
    }
    for (int i = 1; i < cols; ++i){
        //hp[i][0] = min(0, min(hp[i-1][0]+dungeon[i][0], hp[i-1][0]));
        hp[0][i] = hp[0][i-1]+dungeon[0][i];
        previous[0][i] = min(hp[0][i], previous[0][i-1]);
    }
    for (int i = 1; i < rows; ++i){
        for (int j = 1; j < cols; ++j){
            //2x2 cases;
            // hp(i)(j-1) > hp(i-1)(j), < , =
            // previous(i,j-1) < previous(i,j-1), > =;
            if (hp[i][j-1] > hp[i-1][j]){
                //(i,j-1) is better;
                if (hp[i][j-1] >= 0 && hp[i-1][j] <= 0){
                    hp[i][j] = hp[i][j-1] + dungeon[i][j];
                    previous[i][j] = min(previous[i][j-1], hp[i][j]);
                }
                else if (previous[i][j-1] >= previous[i-1][j]){
                    hp[i][j] = hp[i][j-1] + dungeon[i][j];
                    previous[i][j] = min(previous[i][j-1], hp[i][j]);
                }
                else {
                    hp[i][j] = hp[i-1][j] + dungeon[i][j];
                    previous[i][j] = min(previous[i-1][j], hp[i][j]);
                }
            }
            else if (hp[i][j-1] < hp[i-1][j]){
                    //(i-1,j)
                if (hp[i-1][j] >= 0 && hp[i][j-1] <= 0){
                    hp[i][j] = hp[i-1][j] + dungeon[i][j];
                    previous[i][j] = min(previous[i-1][j], hp[i][j]);
                }
                else if (previous[i][j-1] <= previous[i-1][j]){
                    hp[i][j] = hp[i-1][j] + dungeon[i][j];
                    previous[i][j] = min(previous[i-1][j], hp[i][j]);
                }
                else {
                    hp[i][j] = hp[i][j-1] + dungeon[i][j];
                    previous[i][j] = min(previous[i][j-1], hp[i][j]);
                }
            }
            else {
                if (previous[i][j-1] < previous[i-1][j]){
                    hp[i][j] = hp[i-1][j] + dungeon[i][j];
                    previous[i][j] = min(previous[i-1][j], hp[i][j]);
                }
                else {
                    hp[i][j] = hp[i][j-1] + dungeon[i][j];
                    previous[i][j] = min(previous[i][j-1], hp[i][j]);
                }
            }
        }
    }
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            cout<<hp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            cout<<previous[i][j]<<" ";
        }
        cout<<endl;
    }
    return -min(previous[rows-1][cols-1], hp[rows-1][cols-1])+1;
}
int main()
{
    //vector<vector<int>> dungeon = {{-2, -3, 3},{-5, -10, 1},{10, 30, -5}};
    //vector<vector<int>> dungeon = {{1, -3, 3},{0, -2, 0},{-3, -3, -3}};
    vector<vector<int>> dungeon = {{3,-20,30},{-3, 4, 0}};
    //vector<vector<int>> dungeon = {{2,1},{1,-1}};
    cout<<calculateMinimumHP(dungeon);
}
