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
struct line
{
    //ax + by + c = 0;
    double a;
    double b;
    double c;
    line(double aa, double bb, double cc):a(aa), b(bb),c(cc) {}
};
struct HashFunc
{
    //hash function
    std::size_t operator()(const line & l) const
    {
        using std::size_t;
        using std::hash;

        return ((hash<int>()(l.a)
            ^ (hash<int>()(l.b) << 1)) >> 1)
           ^ (hash<int>()(l.c) << 1);
        //return ((hash<int>()(l.a)
         //   ^ (hash<int>()(l.b) << 1)) >> 1);
            //^ (hash<int>()(l.c) << 1);
    }
};
struct EqualKey
{
    bool operator () (const line &l1, const line &l2) const
    {
        return l1.a  == l2.a
            && l1.b == l2.b
            && l1.c  == l2.c;
    }
};
int maxPoints(vector<Point>& points)
{
    unordered_map<line, int, HashFunc, EqualKey> m;
    //O(n^2) solution, transverse all possible line, find the one with maximum points;
    double a = 0;
    double b = 0;
    double c = 0;
    int res = 0;
    //ax + by + c = 0;
    for (int i = 0; i < points.size();++i){
        for (int j = i+1; j < points.size(); ++j){
            if (points[i].x == points[j].x){
                // x = m;
                a = 1.0;
                b = 0.0;
                c = -double(points[i].x);
                line l(a,b,c);
                m[l] += 1;
                res = max(res, m[l]);
            }
            else if (points[i].y == points[j].y ){
                b = 1.0;
                a = 0.0;
                c = -double(points[i].y);
                line l(a,b,c);
                m[l] += 1;
                res = max(res, m[l]);
            }
            else {
                //force a = 1;
                a = 1.0;
                b = - double(points[i].x - points[j].x) / (points[i].y - points[j].y);
                c = - (points[i].x + b* points[i].y);
                line l(a,b,c);
                m[l] += 1;
                res = max(res, m[l]);
            }
            cout<<"("<<points[i].x<<","<<points[i].y<<") ("<<points[j].x<<","<<points[j].y<<")"<<endl;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
    }
    double n = ceil(sqrt(2*res));
    return n;
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
