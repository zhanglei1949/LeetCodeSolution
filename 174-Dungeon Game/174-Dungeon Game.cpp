#include<iostream>
#include<vector>
#include<queue>
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
            // pre always < hp;
            if (previous[i-1][j] < previous[i][j-1]){
                hp[i][j] = hp[i][j-1]+dungeon[i][j];
                previous[i][j] = min(hp[i][j], previous[i][j-1]);
            }
            else if (previous[i-1][j] > previous[i][j-1]){
                hp[i][j] = hp[i-1][j]+dungeon[i][j];
                previous[i][j] = min(hp[i][j], previous[i-1][j]);
            }
            else {
                //previous are equal, turn to hp
                if (hp[i-1][j] < hp[i][j-1]){
                    hp[i][j] = hp[i][j-1]+dungeon[i][j];
                    previous[i][j] = min(hp[i][j], previous[i][j-1]);
                }
                else {
                    hp[i][j] = hp[i-1][j]+dungeon[i][j];
                    previous[i][j] = min(hp[i][j], previous[i-1][j]);
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
    vector<vector<int>> dungeon = {{-2, -3, 3},{-5, -10, 1},{10, 30, -5}};
    //vector<vector<int>> dungeon = {{2,1},{1,-1}};
    cout<<calculateMinimumHP(dungeon);
}
//    //start from the upper left to bottom right, at least 1 when reache target
//    //1. all lattices can contain positive and negative numbers
//    //2. forgot this case: if hp < 0 on some point, then the knight is dead!
//    //so ,we have to track the maximum cost, i.e. the minimum number along the way
//    int rows = dungeon.size();
//    int cols = dungeon[0].size();
//    vector<vector<int> > flag(rows, vector<int>(cols, -2147483648));
//    queue<point> q;
//    point start(0,0,0,dungeon[0][0]);
//    flag[0][0] = min(dungeon[0][0], 0);
//    q.push(start);
//    while (!q.empty()){
//        point cur = q.front();
//        //cout<<cur.x<<" "<<cur.y<<" "<<cur.cost<<" "<<cur.dir<<endl;
//        point tmp = cur;
//        q.pop();
//        if (tmp.dir==0){
//            if (tmp.y + 1< cols){
//                tmp.y += 1;
//                tmp.cost += dungeon[tmp.x][tmp.y];
//                tmp.min_cost =
//                if (tmp.cost < 0) flag[tmp.x][tmp.y] = max(flag[tmp.x][tmp.y], tmp.cost);
//                else flag[tmp.x][tmp.y]= 0;
//                q.push(tmp);
//            }
//            cur.dir = 1;
//            q.push(cur);
//        }
//        else if (tmp.dir==1 ){
//            if (tmp.x + 1 < rows){
//                tmp.x += 1;
//                tmp.dir = 0;
//                tmp.cost += dungeon[tmp.x][tmp.y];
//                if (tmp.cost < 0) flag[tmp.x][tmp.y] = max(flag[tmp.x][tmp.y], tmp.cost);
//                else flag[tmp.x][tmp.y] = 0;
//                q.push(tmp);
//            }
//        }
//    }
////    for (int i = 0; i < rows; ++i){
////        for (int j = 0; j < cols; ++j){
////            cout<<flag[i][j]<<" ";
////        }
////        cout<<endl;
////    }
//    return -flag[rows-1][cols-1]+1;
//}
/*
if (hp[i-1][j] < hp[i][j-1]){
                if (previous[i-1][j] <= previous[i][j-1]){
                    hp[i][j] = min(0,hp[i][j-1]+dungeon[i][j]);
                    previous[i][j] = =min(hp[i][j], previous[i][j-1]);
                }
                else {
                    if (previous[i][j-1] < hp[i-1][j]){
                        //choose i-1,j;
                        hp[i][j] = min(0,hp[i-1][j]+dungeon[i][j]);
                        previous[i][j] = =min(hp[i][j], previous[i-1][j]);
                    }
                    else {

                    }
                }
            }

            */
