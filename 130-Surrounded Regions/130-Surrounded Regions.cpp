#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct pos
{
    int x;
    int y;
    int dir;
    pos(int a, int b, int d = 0):x(a),y(b),dir(d) {}
};
void solve(vector<vector<char>>& board)
{
    queue<pos> q;

    int rows = board.size();
    int cols = board[0].size();
    vector<vector<int>> flag(rows, vector<int> (cols, 0));
    for (int i = 0; i < rows; ++i){
        if (board[i][0] == 'O'){
            q.push(pos(i,0));
            flag[i][0] = 1;
        }
        if (board[i][cols-1] == 'O'){
            q.push(pos(i,cols-1));
            flag[i][cols-1] = 1;
        }
    }
    for (int i = 1; i < cols-1; ++i){
        if (board[0][i] == 'O'){
            q.push(pos(0,i));
            flag[0][i] = 1;
        }
        if (board[rows-1][i] == 'O'){
            q.push(pos(rows-1,i));
            flag[rows-1][i] = 1;
        }
    }
    int direction[4][2] = {0,1,1,0,0,-1,-1,0};
    while (!q.empty()){
        pos p = q.front();
        q.pop();
        if (p.dir == 4) continue;
        int tmpx = p.x + direction[p.dir][0];
        int tmpy = p.y + direction[p.dir][1];
        //out of range
        if (tmpx < 0 || tmpx >= rows || tmpy < 0 || tmpy >= cols || board[tmpx][tmpy] == 'X'){
            p.dir++;
            q.push(p);
            continue;
        }
        //now must be o
        if (!flag[tmpx][tmpy]){
            flag[tmpx][tmpy]=1;
            q.push(pos(tmpx,tmpy));
        }
        p.dir++;
        q.push(p);
    }
    for (int i = 0; i < board.size(); ++i){
        for (int j = 0; j < board[i].size(); ++j){
            if (!flag[i][j]) board[i][j] = 'X';
        }
    }
//    for (int i = 0; i < board.size(); ++i){
//        for (int j = 0; j < board[i].size(); ++j){
//            cout<<board[i][j]<<" ";
//        }
//        cout<<endl;
//    }

}
int main()
{
    vector<vector<char>> board={{'X','X','X','X'},
                                {'X','O','O','X'},
                                {'X','X','O','X'},
                                {'X','O','O','O'}
    };
    solve(board);
    return 0;
}
