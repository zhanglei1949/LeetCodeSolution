#include<iostream>
#include<vector>
using namespace std;
int minimumTotal(vector<vector<int> >& triangle)
{
    if (triangle.size()==0) return 0;

    int m = triangle.size();
    int *arr = new int [m];
    for (int i = 0; i < m; ++i) arr[i] = triangle[m-1][i];
    for (int i = m-2; i >= 0; --i){
        for (int j = 0; j <= i; ++j){
            arr[j] = min(arr[j], arr[j+1])+triangle[i][j];
        }
    }
    return arr[0];
}
int main()
{
    vector<vector<int> > triangle;
    vector<int> tmp;
    tmp.push_back(2);
//    triangle.push_back(tmp);
//    tmp.clear();
//    tmp.push_back(3);
//    tmp.push_back(4);
//    triangle.push_back(tmp);
//    tmp.clear();
//    tmp.push_back(6);
//    tmp.push_back(5);
//    tmp.push_back(7);
//    triangle.push_back(tmp);
//    tmp.clear();
//    tmp.push_back(4);
//    tmp.push_back(1);
//    tmp.push_back(8);
//    tmp.push_back(3);
    triangle.push_back(tmp);
    cout<<minimumTotal(triangle);
}
