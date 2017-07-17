#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int candy(vector<int>& ratings)
{
    if (ratings.size()==0) return 0;
    int cur = 0;
    int res = 0;
    stack<int> s;
    //scan twice
    vector<int> v(ratings.size(), 0);
    v[0] = 1;
    for (int i = 1; i < ratings.size(); ++i){
        if (ratings[i] > ratings[i-1])
            v[i] = v[i-1] + 1;
        else v[i] = 1;
    }
    for (int i = 0; i < ratings.size(); ++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    for (int i = ratings.size()-1; i > 0; --i){
        if (ratings[i] < ratings[i-1])
            v[i-1] = max(v[i] + 1, v[i-1]);

    }
    for (int i = 0; i < ratings.size(); ++i){
        res += v[i];
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return res;

}
int main()
{
    vector<int> ratings={1,2,2};
    cout<<candy(ratings)<<endl;
}
