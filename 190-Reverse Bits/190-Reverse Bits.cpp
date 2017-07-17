#include<iostream>

using namespace std;

uint32_t reverseBits(uint32_t n)
{
    uint32_t odd_arr[] = {0xAAAAAAAA, 0xCCCCCCCC, 0xF0F0F0F0, 0xFF00FF00, 0xFFFF0000};
    // 1010бнбн
    uint32_t even_arr[] = {0x55555555, 0x33333333, 0x0F0F0F0F0F, 0x00FF00FF, 0x0000FFFF };
    //0101
    uint32_t res = n;
    int cnt = 0;
    for (int i = 1; i < 32; ){
        uint32_t odd = odd_arr[cnt];
        uint32_t even = even_arr[cnt++];
        //generate right odd and even

        uint32_t get_odd = res & odd;
        uint32_t get_even = res & even;
        res = (get_odd >> i) | (get_even << i);
        i = i*2;
    }
    return res;
}
int main()
{
    uint32_t n = 43261596;
    cout<<reverseBits(n);
}
