#include<iostream>
#include<vector>

using namespace std;
bool exist(vector<vector<char> > & board, string &word, int x, int y, int word_ind)
{
    cout<<x<<" "<<y<<" "<<word_ind<<endl;
    if (word_ind == word.size()) return true;

    if (board[x][y] != word[word_ind]) return false;
    //if equal, make board[x][y] invalid
    board[x][y] = '\0';
    //cout<<12<<endl;
    bool res = false;
    if (word_ind == word.size()-1) return true;
    if (x+1 < board.size() && board[x+1][y]!='\0')    res = res || exist(board, word, x+1, y, word_ind+1);
    if (y+1 < board[x].size() && board[x][y+1]!='\0') res = res || exist(board, word, x, y+1, word_ind+1);
    if (x-1 >= 0 && board[x-1][y]!='\0')               res = res || exist(board, word, x-1, y, word_ind+1);
    if (y-1 >= 0 && board[x][y-1]!='\0')               res = res || exist(board, word, x, y-1, word_ind+1);
    board[x][y] ^= 256;
    return res;
}
bool exist(vector<vector<char> > &board, string word)
{
    //back tracking; dfs
    if (board.size()==0) return false;
    //int board_len = board.size()*board[0].size();

    for (int i = 0; i < board.size(); ++i){
        for (int j = 0; j < board[i].size(); ++j){
            if (exist(board, word, i, j, 0)) return true;
        }
    }
    return false;
}
int main()
{
    string word="aaa";
    vector<vector<char> > board;
    vector<char> tmp;
    tmp.push_back('a');
    tmp.push_back('a');
    //tmp.push_back('B');
    //tmp.push_back('C');
    board.push_back(tmp);
//    tmp.clear();
//    tmp.push_back('S');
//    tmp.push_back('F');
//    tmp.push_back('C');
//    board.push_back(tmp);
//    tmp.clear();
//    tmp.push_back('A');
//    tmp.push_back('D');
//    tmp.push_back('E');
//    board.push_back(tmp);
    cout<<exist(board, word);
}
