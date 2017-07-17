#include<iostream>
using namespace std;


bool isPalindrome(string s) {
        int len = s.size();
        if (len<=1) return true;
    	int l = 0;
        int r = len-1;
        //only consider alphanumeric
        while (l < r){
            //skip
            //cout<<!(s[l] >= 'a' && s[l] <= 'z')<< !(s[l] >= 'A' && s[l] <= 'Z')<< !(s[l] >= '0' && s[l] <= '9')<<endl;
            while ( !(s[l] >= 'a' && s[l] <= 'z') && !(s[l] >= 'A' && s[l] <= 'Z') && !(s[l] >= '0' && s[l] <= '9') ){
             	l++;
                if (l >= r) break;
            }
            cout<<l<<" "<<r<<endl;
            while ( !(s[r] >= 'a' && s[r] <= 'z') && !(s[r] >= 'A' && s[r] <= 'Z') && !(s[r] >= '0' && s[r] <= '9') ){
             	r--;
                if (r <= l) break;
            }
            cout<<l<<" "<<r<<endl;
            if (r <= l) break;
            char sl = s[l];
            char sr = s[r];
            if (sl >= 'A' && sl <= 'Z') sl = 'a'+(sl-'A');
            if (sr >= 'A' && sr <= 'Z') sr = 'a'+(sr-'A');
            cout<<sl<<" "<<sr<<endl;
            if (sl != sr) return false;
            else{
                l++;
                r--;
            }
        }
        return true;
    }
int main()
{
    string s = "ab";
    cout<<isPalindrome(s);

}
