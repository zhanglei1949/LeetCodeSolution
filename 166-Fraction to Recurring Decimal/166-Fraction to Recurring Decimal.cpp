#include<iostream>
#include<sstream>
#include<map>
#include<cmath>
using namespace std;
string to_string(int x)
{
    stringstream res;
    res << x;
    return res.str();
}
string fractionToDecimal(long long numerator, long long denominator)
{
    string res;
    if (numerator == 0) return "0";
    if ((numerator > 0 && denominator > 0) || (numerator < 0 && denominator < 0)){
        // positive
    }
    else res += "-";//negative;
    numerator = abs(numerator);
    denominator = abs(denominator);
    res += to_string(numerator / denominator);
    //now the fraction part;
    long long remainder = numerator % denominator;
    if (remainder == 0) return res;
    res += '.';
    map<int, int> m;
    //m[i] refer to the position where i appears
    while (remainder != 0){
        //cout<<res<<endl;
        //cout<<remainder<<endl;
        long long  r = (remainder * 10)/ denominator;
        if (m[remainder] > 0){
            res.insert(m[remainder], 1, '(');
            res+=")";
            return res;
        }
        m[remainder] = res.size();
        res += to_string(r);
        remainder = remainder*10 % denominator;
    }
    return res;
}
int main()
{
    int numerator = -1;
    int denominator = -2147483648;
    cout<<fractionToDecimal(numerator, denominator);
}
