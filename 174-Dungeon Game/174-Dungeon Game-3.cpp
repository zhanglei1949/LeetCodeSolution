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
    vector<vector<int>> hp(rows, vector<int> (cols, 1));

    //from bottom right to upper left;
    //what does each element represent?minimum hp need when entering this room;
    /*
    max(1-
    */
    if (dungeon[rows-1][cols-1] >= 0 ){
        hp[rows-1][cols-1] = 1;
    }
    else hp[rows-1][cols-1] = -dungeon[rows-1][cols-1] + 1;

    for (int i = cols-2; i >= 0; --i){
        if (hp[rows-1][i+1] - dungeon[rows-1][i] <= 0)
            hp[rows-1][i] = 1;
        else hp[rows-1][i] = hp[rows-1][i+1] - dungeon[rows-1][i];
    }
    for (int i = rows-2; i >= 0; --i){
        if (hp[i+1][cols-1] - dungeon[i][cols-1] <= 0)
            hp[i][cols-1] = 1;
        else hp[i][cols-1] = hp[i+1][cols-1]- dungeon[i][cols-1];
    }
    for (int i = rows-2; i >= 0; --i){
        for (int j = cols-2; j >= 0; --j){
            //for hp[i][j], choose from i+1,j and i,j+1;
            int tmp = min(hp[i+1][j],hp[i][j+1]) - dungeon[i][j];
            if (tmp <= 0)
                hp[i][j] = 1;
            else hp[i][j] = tmp;
        }
    }
//    for (int i = 0; i < rows; ++i){
//        for (int j = 0; j < cols; ++j){
//            cout<<hp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return hp[0][0];
}
int main()
{
    //vector<vector<int>> dungeon = {{-2, -3, 3},{-5, -10, 1},{10, 30, -5}};
    //vector<vector<int>> dungeon = {{1, -3, 3},{0, -2, 0},{-3, -3, -3}};
    //vector<vector<int>> dungeon = {{3,-20,30},{-3, 4, 0}};
    //vector<vector<int>> dungeon = {{2,1},{1,-1}};
    cout<<calculateMinimumHP(dungeon);
}
