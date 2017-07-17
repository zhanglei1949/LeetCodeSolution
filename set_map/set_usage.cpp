#include<set>
#include<iostream>
using namespace std;

int main()
{
    set<int> s;
    s.insert(2);
    s.insert(0);
    s.insert(4);
    s.insert(3);
    s.insert(5);
    set<int>::iterator iter;
    for (iter = s.begin(); iter != s.end(); ++iter){
        cout<<*iter<<endl;
    }
}
