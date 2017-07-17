#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;

struct Point
{
    int x;
    int y;
    Point():x(0), y(0) {}
    Point(int a, int b):x(a), y(b) {}
};
int maxPoints(vector<Point>& points)
{
    unordered_map<double, int> m;// xielv: cnt
    //O(n^2) solution, transverse all possible line, find the one with maximum points;
}
int main()
{
    vector<Point> points;
    points.push_back(Point(3,1));
    points.push_back(Point(12,3));
    //points.push_back(Point(3,3));
    points.push_back(Point(3,1));
    points.push_back(Point(-6,-1));
    //points.push_back(Point(7,7));
    cout<<maxPoints(points);
}
