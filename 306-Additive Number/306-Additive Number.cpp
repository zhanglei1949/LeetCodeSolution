#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string to_string(int a)
{
    stringstream s;
    s<<a;
    return s.str();
}
string add(string & a, string & b)
{
    string res;
    int index_a = a.size()-1;
    int index_b = b.size()-1;
    int next = 0;
    while (index_a >= 0 && index_b >= 0){
        int tmp = (a[index_a]-'0') + (b[index_b]-'0') + next;
        next = tmp / 10;
        tmp = tmp %10;
        res = to_string(tmp) + res;
        index_a--;
        index_b--;
    }
    while (index_a >= 0){
        if (next) {
            int tmp = (a[index_a] - '0' ) + next;
            next = tmp/10;
            tmp = tmp%10;
            res = to_string(tmp) + res;
        }
        else res = a[index_a] + res;
        index_a --;
    }
    while (index_b >= 0){
        if (next) {
            int tmp = (b[index_b] - '0' ) + next;
            next = tmp/10;
            tmp = tmp%10;
            res = to_string(tmp) + res;
        }
        else res = b[index_b] + res;
        index_b --;
    }
    if (next) res = to_string(next) + res;
    return res;
}

bool isAdditiveNumber(string num)
{
    //no leading zeros;
    int len = num.size();
    if (len==0) return true;
    //the key is to find the first two
    for (int i = 1; i < len; ++i){
        for (int j = i+1; j < len; ++j){
            string first = num.substr(0, i);
            string second = num.substr(i, j-i);

            if ( (first.size()!=1 && first[0]=='0') || ( second.size() != 1 && second[0] =='0'))
                continue;
            //check first + second ==third and circulate
            int third_start = j;

            while (true){
                //cout<<"third start at: "<<third_start<<endl;
                if (third_start == num.size()) return true;
                string third = add(first, second);
                if (third_start + third.size() > num.size()) break;
//                cout<<"first: "<<first<<endl;
//                cout<<"second: "<<second<<endl;
//                cout<<"third: "<<third<<endl;
//                cout<<"expected: "<<num.substr(third_start, third.size())<<endl;
                if (third != num.substr(third_start, third.size())){
                    break;
                }
                else{
                    first = second;
                    second = third;
                    third_start = third_start + third.size();
                }
                //cout<<"---------------------------------------"<<endl;
            }
        }

    }
    return false;
}
int main()
{
    int a = 3;
    string s = "12";
    //cout<<add("123","123")<<endl;
    //cout<<add("123","0")<<endl;
    //cout<<add("123","7")<<endl;
    //cout<<add("0","0")<<endl;
    cout<<isAdditiveNumber(s);
    return 0;
}
