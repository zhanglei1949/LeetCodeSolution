#include<iostream>

using namespace std;

int hammingWeight(uint32_t n) {
    uint32_t flag = 1;
    int res = n & flag;
    for (int i = 0; i < 31; ++i){
        n = n >> 1;
        cout<<n<<endl;
        res += n & flag;
    }
    return res;
}

int main()
{
    uint32_t n = 1;
    cout<<hammingWeight(n)<<endl;
}
