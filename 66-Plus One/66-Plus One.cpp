#include<iostream>
#include<vector>
using namespace std;
 vector<int> plusOne(vector<int>& digits)
 {
     vector<int> res(digits);
    int length = res.size();
    int plus_one = 1;
    for (int i = length-1; i >= 0; --i){
        if (plus_one){
            plus_one = (res[i]+1)/10;
            res[i] = (res[i]+1)%10;
        }
        else continue;
    }
    if (plus_one) res.insert(res.begin(),1);
    return res;
 }
int main()
{
    vector<int> digits;
    digits.push_back(0);
    //digits.push_back(0);
    //digits.push_back(0);
    vector<int> res = plusOne(digits);
    for (int i = 0; i < res.size(); ++i){
        cout<<res[i]<<" ";
    }
}
