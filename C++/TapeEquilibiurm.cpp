#include <cmath>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++11
    int minimalDifference=0,Difference=0,SumOfAllElements=0;
    for(unsigned int i=0;i<A.size();i++)
    {
        SumOfAllElements+=A[i];
    }
    int LeftSide=0,RightSide=SumOfAllElements;
    for(unsigned int i=0;i<A.size()-1;i++)
    {
        LeftSide+=A[i];
        RightSide-=A[i];
        Difference=abs(LeftSide-RightSide);
        if((i==0)||(Difference<minimalDifference))
        {
            minimalDifference=Difference;
        }
    }
    return minimalDifference;
}
