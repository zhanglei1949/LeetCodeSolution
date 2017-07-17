#include<iostream>

using namespace std;

int arrangeCoins(int n) {
        long long add  = 1;
        int height = 1;
        while (add <= n){
            height++;
            add += height;

        }
        return height-1;
}
int main()
{
    cout<<arrangeCoins(2147483647)<<endl;
    return 0;
}
