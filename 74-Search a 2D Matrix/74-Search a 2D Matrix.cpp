#include<iostream>
#include<vector>
using namespace std;
int search_for_row(vector<vector<int> > &matrix, int target, int m, int n)
{
    int a = 0;
    int b = m-1;
    int mid;
    while (a!=b){
        mid = (a+b)/2;
        if (target > matrix[mid][n-1]){
            a = mid+1;
        }
        else if (target < matrix[mid][0]){
            b = mid-1;
        }
        else return mid;
    }
}
bool search_in_row(vector<vector<int> > &matrix, int target, int row)
{
    int a = 0;
    int b = matrix[row].size()-1;
    int mid;
    while (a!=b){
        mid = (a+b)/2;
        if (target == matrix[row][mid]){
            return true;
        }
        else if (target > matrix[row][mid]){
            a = mid+1;
        }
        else b = mid-1;
    }
    if (matrix[row][a]==target) return true;
    else return false;
}
bool searchMatrix(vector<vector<int> >& matrix, int target)
{
    if (matrix.size()==0) return 0;
    if (matrix.size()==1 && matrix[0].size()==0) return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    int row = search_for_row(matrix, target, m, n);
    cout<<row<<endl;
    return search_in_row(matrix, target, row);
}
int main()
{
    vector<vector<int> > matrix;
    vector<int> row;
    row.push_back(1);
    row.push_back(1);
    matrix.push_back(row);
//    row.push_back(1);
//    row.push_back(3);
//    row.push_back(5);
//    matrix.push_back(row);
//    row.clear();
//    row.push_back(10);
//    row.push_back(11);
//    row.push_back(16);
//    matrix.push_back(row);
//    row.clear();
//    row.push_back(23);
//    row.push_back(30);
//    row.push_back(34);
//    matrix.push_back(row);
    cout<<searchMatrix(matrix, 0);
}
