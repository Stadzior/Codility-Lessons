// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <cmath>

int solution(int N) {
    int FactorCount=0;
    double LeftPivot=1,RightPivot=ceil(N/LeftPivot);
    while(RightPivot-LeftPivot>1)
    {
        if(LeftPivot*RightPivot==N)
        {
            FactorCount+=2;
        }
        LeftPivot++;
        RightPivot=ceil(N/LeftPivot);
    }
    if(LeftPivot*RightPivot==N)
    {
        switch((int)(RightPivot-LeftPivot))
        {
            case 0:
            {
                FactorCount++;            
                break;
            }
            case 1:
            {
                FactorCount+=2;
                break;
            }
        }
    }
    return FactorCount;
}
