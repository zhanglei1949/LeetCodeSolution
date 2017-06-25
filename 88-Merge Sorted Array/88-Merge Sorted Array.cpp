#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    if (n == 0) return ;
    for (int i = m-1; i >= 0; --i){
        nums1[i+n] = nums1[i];
    }
    int i = n;
    int j = 0;
    int cur = 0;
    while (i < m+n && j < n){
        if (nums1[i] < nums2[j]){
            nums1[cur++] = nums1[i++];
        }
        else {
            nums1[cur++] = nums2[j++];
        }
    }
    while (j < n) nums1[cur++] = nums2[j++];
}
int main()
{
    int m , n;
    m = 3;
    n = 4;
    vector<int> nums1(m+n);
    vector<int> nums2(n);
    for (int i = 0; i < m; ++i){
        nums1[i] = 2*i+3;
    }
    for (int i = 0; i < n; ++i){
        nums2[i] = 2*i+2;
    }
    merge(nums1, m, nums2, n);
    for (int i = 0; i < m+n; ++i){
        cout<<nums1[i]<<" ";
    }
}
