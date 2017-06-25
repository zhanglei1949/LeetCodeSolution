#include<iostream>
#include<vector>
#include<map>
using namespace std;
void setRowZero(int row, vector<vector<int> > &matrix)
{
    for (int i = 0; i < matrix[row].size(); ++i){
        matrix[row][i] = 0;
    }
}
void setColZero(int col, vector<vector<int> > &matrix)
{
    for (int i = 0; i < matrix.size(); ++i){
        matrix[i][col] = 0;
    }
}
void setZeroes(vector<vector<int> > & matrix)
{
    if (matrix.size()==0) return ;
    map<int, int> row;
    map<int, int> col;
    for (int i = 0;i < matrix.size(); ++i){
        for (int j = 0; j < matrix[0].size(); ++j){
            if (matrix[i][j]==0){
                if (!row[i]) row[i] = 1;
                if (!col[j]) col[j] = 1;
            }
        }
    }
    map<int, int>::iterator iter;
    for (iter = row.begin(); iter != row.end(); ++iter){
        setRowZero(iter->first, matrix);
    }
    for (iter = col.begin(); iter != col.end(); ++iter){
        setColZero(iter->first, matrix);
    }

}
int main()
{
    vector<vector<int> > matrix;
    vector<int> row;
//    row.push_back(1);
//    row.push_back(1);
//    row.push_back(0);
//    matrix.push_back(row);
//    row[1] = 1;
//    matrix.push_back(row);
    row.push_back(0);
    matrix.push_back(row);
    setZeroes(matrix);
    for (int i = 0;i < matrix.size(); ++i){
        for (int j = 0; j < matrix[0].size(); ++j){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
