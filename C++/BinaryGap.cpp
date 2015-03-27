// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
using namespace std;

int solution(int N) {
    int BinaryGap=0,tempGap=0;
    bool flag=0;
    do{
        if((N%2)&&(N!=0))
        {
            flag=1;
            if(tempGap>BinaryGap)
            {
                BinaryGap=tempGap;
            }
            tempGap=0;
        }
        else
        {
            if(flag==1)
            {
            tempGap++;
            }
        }
        N/=2;
    }while(N>0);
    return BinaryGap;
}
