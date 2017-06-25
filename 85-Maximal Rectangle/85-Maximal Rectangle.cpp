#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int largestRectangleHistogram(int *height, int row, int len)
{
    stack<int> s;
    int res = 0;
    for (int i = 0; i < len; ++i){
        if (s.empty() || height[s.top()] <= height[i]){
            s.push(i);
        }
        else {
            int poped = height[s.top()];
            s.pop();
            if (s.empty()){
                if (poped*(i) >= res){
                    res = poped*i;
                }
            }
            else {
                if (poped*(i-s.top()-1) >= res){
                    res = poped*(i-s.top()-1);
                }
            }
            i--;
        }
    }
    while (!s.empty()){
        int poped = height[s.top()];
        s.pop();
        if (s.empty()){
            if (poped*len >= res){
                res = poped*(len);
            }
        }
        else {
            if (poped*(len-s.top()-1) >= res){
                res = poped*(len-s.top()-1);
            }
        }
    }
    return res;
}
int maximalRectangle(vector<vector<char> >& matrix)
{
    int res = 0;
    int x1 = 0; int x2 = 0;
    int y1 = 0; int y2 = 0;
    if (matrix.size()==0 || matrix[0].size()==0) return 0;
    // row by row, take 0-i row matrix as a picture of histogram.
    // i.e. find the largest rectangle in histogram
    int m = matrix.size();
    int n = matrix[0].size();
    int *height = new int [n];
    for (int i = 0; i < n; ++i) height[i] = 0;
    //for (int i = 0; i < n; ++i) cout<<height[i]<<endl;
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            if (matrix[i][j]=='1') height[j]+=1;
            else height[j] = 0;
        }
        // update
//        for (int j = 0; j < n; ++j) cout<<height[j]<<" ";
//        cout<<endl;
        int cur = largestRectangleHistogram(height, i, n);
        res = max(cur, res);

    }
    return res;
}
int main()
{
    vector<vector<char> > matrix;
    vector<char> tmp;
    tmp.push_back('1');
    tmp.push_back('0');
    tmp.push_back('1');
    tmp.push_back('1');
    tmp.push_back('0');
    matrix.push_back(tmp);
    tmp.clear();
    tmp.push_back('1');
    tmp.push_back('0');
    tmp.push_back('1');
    tmp.push_back('1');
    tmp.push_back('1');
    matrix.push_back(tmp);
    tmp.clear();
    tmp.push_back('1');
    tmp.push_back('1');
    tmp.push_back('1');
    tmp.push_back('1');
    tmp.push_back('1');
    matrix.push_back(tmp);
    tmp.clear();
    tmp.push_back('1');
    tmp.push_back('0');
    tmp.push_back('0');
    tmp.push_back('1');
    tmp.push_back('0');
    matrix.push_back(tmp);
    cout<<maximalRectangle(matrix);
}


//void findLargestRectangleInHistogram(int &x1, int &x2, int *x, int len)
//{
//    stack<int> s;
//    int res = 0;
//    for (int i = 0; i < len; ++i){
//        if (s.empty() || x[i] >= x[s.top()]){
//            s.push(i);
//        }
//        else {
//            int poped = x[s.top()];
//            //height is poped!
//            s.pop();
//            if (s.empty()){
//                if (poped*i >= res){
//                    res = poped*i;
//                    x1 = 0;
//                    x2 = i-1;
//                }
//            }
//            else{
//                if (poped*(i-s.top()-1) >= res){
//                    res = poped*(i-s.top()-1);
//                    x1 = s.top()+1;
//                    x2 = i-1;
//                }
//            }
//            i--;
//        }
//    }
//    while (!s.empty()){
//        int poped = x[s.top()];
//        s.pop();
//        if (s.empty()){
//            if (poped*len >= res){
//                res = poped*len;
//                x1 = 0;
//                x2 = len-1;
//            }
//        }
//        else {
//            if (poped*(len-s.top()-1) >= res){
//                res = poped*(len-s.top()-1);
//                x1 = s.top()+1;
//                x2 = len-1;
//            }
//        }
//    }
//    cout<<"findLargestRectangle: "<<res<<endl;
//}
//int maximalRectangle(vector<vector<char> > &matrix)
//{
//    int res = 0;
//    if (matrix.size() == 0) return 0;
//    int m = matrix.size();
//    int n = matrix[0].size();
//    //based on maximal histgram
//    int *x = new int [n];
//    int *y = new int [m];
//    for (int i = 0; i < n; ++i) x[i] = 0;
//    for (int i = 0; i < m; ++i) y[i] = 0;
//    for (int i = 0; i < m; ++i){
//        for (int j = 0; j < n; ++j){
//            x[j]+=matrix[i][j]-'0';
//            y[i]+=matrix[i][j]-'0';
//        }
//    }
//    for (int i = 0; i < n; ++i){
//        cout<<x[i]<<" ";
//    }
//    cout<<endl;
//    for (int i = 0; i < m; ++i){
//        cout<<y[i]<<" ";
//    }
//    //find the largest rectangle in histograms for array x and y;
//    int x1 = 0; int y1 = 0;
//    int x2 = 0; int y2 = 0;
//    findLargestRectangleInHistogram(x1, x2, x, n);
//    findLargestRectangleInHistogram(y1, y2, y, m);
//    cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
//    return (x2-x1+1)*(y2-y1+1);
//}
