#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct point
{
    int x,y,height;
    point(int xx, int yy, int h):x(xx), y(yy), height(h){}
};
struct cmp
{
    bool operator () (const point &a, const point &b)
    {
        return a.height > b.height;
    }
};
int trapRainWater(vector<vector<int>>& heightMap)
{
    int rows = heightMap.size();
    int cols = heightMap[0].size();
    if (rows <= 2 || cols <= 2) return 0;
    vector<vector<int>> visited(rows, vector<int> (cols,0));
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int res = 0;// for return
    //1. one 2-d array keep visited
    //2. priority_queue
    priority_queue<point, vector<point>, cmp> q;
    for (int i = 0; i < rows; ++i){
        point p(i,0,heightMap[i][0]);
        q.push(p);
        point pp(i,cols-1,heightMap[i][cols-1]);
        q.push(pp);
        visited[i][0] = 1;
        visited[i][cols-1] = 1;
        if (i==0||i==rows-1){
            for (int j = 1; j < cols-1; ++j){
                point ppp(i,j,heightMap[i][j]);
                q.push(ppp);
                visited[i][j] = 1;
            }
        }
    }
//    for (int i = 0; i < rows; ++i){
//        for (int j = 0; j < cols; ++j){
//            cout<<visited[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    int maximum = 0;
    while (!q.empty()){
        point cur = q.top();
        //cout<<cur.x<<" "<<cur.y<<" "<<cur.height<<endl;
        q.pop();
        maximum = max(maximum, cur.height);
        for (int i = 0; i < 4; ++i){
            if (cur.x + dir[i][0] < rows && cur.x + dir[i][0] >= 0 &&
                cur.y + dir[i][1] < cols && cur.y + dir[i][1] >= 0 &&
                !visited[cur.x + dir[i][0]][cur.y+dir[i][1]]){
                //cout<<"next: "<<cur.x+dir[i][0]<<" "<<cur.y+dir[i][1]<<" "<<heightMap[cur.x+dir[i][0]][cur.y+dir[i][1]]<<endl;
                if (heightMap[cur.x+dir[i][0]][cur.y+dir[i][1]] < maximum) res += maximum - heightMap[cur.x+dir[i][0]][cur.y+dir[i][1]];
                visited[cur.x+dir[i][0]][cur.y+dir[i][1]] = 1;
                point tmp(cur.x+dir[i][0], cur.y+dir[i][1], heightMap[cur.x+dir[i][0]][cur.y+dir[i][1]]);
                q.push(tmp);
            }
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> heightMap={{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    cout<<trapRainWater(heightMap)<<endl;
}
