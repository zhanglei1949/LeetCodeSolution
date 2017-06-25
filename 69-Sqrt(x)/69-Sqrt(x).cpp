#include<iostream>
#include<cmath>
using namespace std;
int sqrt(int x)
{
    double x_i = x/2;
    double x_i_plus_1;
    while (true){
        x_i_plus_1 = (x_i + x/ x_i)/2.0;
        if (abs(x_i_plus_1-x_i)<0.001)
            break;
        x_i = x_i_plus_1;
    }
    return int(x_i_plus_1);
}
int main()
{
    int x;
    cin>>x;
    cout<<sqrt(x);
}
