#include<iostream>
#include<vector>
using namespace std;
string minWindow(string s, string t)
{
    //
    int t_len = t.size();
    int s_len = s.size();
    if (!t_len || !s_len) return "";
    int *flag = new int [128];
    int *cnt = new int [128];
    for (int i = 0; i < 128; ++i){
        flag[i] = 0; cnt[i] = 0;
    }
    for (int i = 0; i < t_len; ++i){
        cnt[t[i]]++;
        flag[t[i]]=1;
    }
    int left = 0;
    int right = -1;
    int min_len = s_len+1;
    int min_ind = -1;
    int target_nums = t_len;
    while (left < s_len && right < s_len){
        //cout<<left<<" "<<right<<endl;
        if (target_nums){
            right++;
            cnt[s[right]]--;
            // can not put explicitly assign flag[s[right]] to zero, because it may appear multiple times.
            if (flag[s[right]] && cnt[s[right]] >= 0){
                target_nums--;
            }
        }
        //all target included.
        else {
            if (min_len > right-left+1){
                min_len = right-left+1;
                min_ind = left;
            }
            cnt[s[left]]++;
            // means we let left move forward
            if (flag[s[left]] && cnt[s[left]] > 0){
                target_nums++;
            }
            left++;
        }
    }
    if (min_ind==-1) return "";
    return s.substr(min_ind, min_len);

}

int main()
{
    string s = "A";
    string t = "A";
    cout<<minWindow(s,t);
}
