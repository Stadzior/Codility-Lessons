#include <cmath>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++11
    int minimalDifference,Difference=100,SumOfAllElements=0;
    for(int i=0;i<A.size();i++)
    {
        SumOfAllElements+=A[i];
    }
    int LeftSide=0,RightSide=SumOfAllElements;
    for(int i=0;i<A.size()-1;i++)
    {
        LeftSide+=A[i];
        RightSide-=A[i];
        Difference=abs(LeftSide-RightSide);
        cout<<Difference;
        if((i==0)||(Difference<minimalDifference))
        {
            minimalDifference=Difference;
        }
    }
    return minimalDifference;
}