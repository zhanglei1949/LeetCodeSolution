#include<iostream>

using namespace std;
bool isNumber(string s)
{
    enum inputType
    {
        invalid, space, sign, digit, dot, expo, num_inputs
    };
    int transitionTable[9][6];
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 6; ++j){
            transitionTable[i][j] = -1;
        }
    }
    transitionTable[0][1] = 0;  transitionTable[0][2] = 3;  transitionTable[0][3] = 1; transitionTable[0][4] = 2;
    transitionTable[1][1] = 8;  transitionTable[1][3] = 1;  transitionTable[1][4] = 4; transitionTable[1][5] = 5;
    transitionTable[2][3] = 4;
    transitionTable[3][3] = 1;  transitionTable[3][4] = 2;
    transitionTable[4][1] = 8;  transitionTable[4][3] = 4; transitionTable[4][5] = 5;
    transitionTable[5][2] = 6;  transitionTable[5][3] = 7;
    transitionTable[6][3] = 7;
    transitionTable[7][1] = 8;  transitionTable[7][3] = 7;
    transitionTable[8][1] = 8;
    int state = 0;
    int index = 0;
    while (index < s.size()){
        inputType input = invalid;
        if (s[index]==' ' || s[index]=='\t')
            input = space;
        else if (s[index]=='+' || s[index]=='-')
            input = sign;
        else if (s[index]>='0' && s[index]<='9')
            input = digit;
        else if (s[index]=='.')
            input = dot;
        else if (s[index]=='e'||s[index]=='E')
            input = expo;

        state = transitionTable[state][input];

        if (state == -1)
            return false;
        else ++index;
    }
    return state==1 || state == 4 || state == 7 || state == 8;
}
int main()
{
    string s;
    cin>>s;
    cout<<isNumber(s);
}
