// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include "math.h"
int Max(vector<int> &A)
{
    int MaxValue=A[0];
    for(unsigned int i=1;i<A.size();i++)
    {
        if(A[i]>MaxValue)
        {
            MaxValue=A[i];
        }
    }
    return MaxValue;
}

int Min(vector<int> &A)
{
    int MinValue=A[0];
    for(unsigned int i=1;i<A.size();i++)
    {
        if(A[i]<MinValue)
        {
            MinValue=A[i];
        }
    }
    return MinValue;
}
int solution(vector<int> &A) {
    // write your code in C++11
    vector<int>OccuringVector;
    for(unsigned int i=0;i<A.size();i++)
    {
        A[i]=abs(A[i]);
    }
    int MaxA = Max(A);
    int MinA = Min(A);
    for(int i=MinA;i<MaxA+1;i++)
    {
        OccuringVector.push_back(0);
    }
    for(unsigned int i=0;i<A.size();i++)
    {
        OccuringVector[A[i]-MinA]=1;
    }
    int DistinctCount=0;
    for(unsigned int i=0;i<OccuringVector.size();i++)
    {
        if(OccuringVector[i])
        {
            DistinctCount++;
        }
    }
    return DistinctCount;
}
