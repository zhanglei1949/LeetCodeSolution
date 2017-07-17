#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(const vector<int> & a, const vector<int> & b)
{
    if (a[1] < b[1])
        return true;
    else if (a[1] == b[1])
        return a[0] > b[0];
    else return false;
}
int scheduleCourse(vector<vector<int> >& courses)
{
    //start from 1st day
    //course must be finished before courses[i][1];
    //i.e must take before or on courses[i][1] - courses[i][0]
    sort(courses.begin(), courses.end(), cmp);
    for (int i = 0; i < courses.size(); ++i){
        cout<<courses[i][0]<<" "<<courses[i][1]<<endl;
    }
    int cur = 1;
    int cnt = 0;
    for (int i = 0; i < courses.size(); ++i){
        if (courses[i][1] - courses[i][0] >= cur){
            cur += courses[i][0];
            cnt+=1;
        }
    }
    return cnt;
}
int main()
{
    vector<vector<int> > courses;
    vector<int> tmp(2,0);
    tmp[0] = 3; tmp[1] = 6;
    courses.push_back(tmp);
    tmp[0] = 2; tmp[1] = 3;
    courses.push_back(tmp);
    tmp[0] = 4; tmp[1] = 6;
    courses.push_back(tmp);
    tmp[0] = 7; tmp[1] = 10;
    courses.push_back(tmp);
    tmp[0] = 7; tmp[1] = 8;
    courses.push_back(tmp);
    tmp[0] = 9; tmp[1] = 10;
    courses.push_back(tmp);
    cout<<scheduleCourse(courses)<<endl;
}
