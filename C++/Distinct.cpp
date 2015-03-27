// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <cmath>
using namespace std;

int solution(vector<int> &A) {
    int NumberOfDistinctValues=0;
    if(A.size()>0)
    {
        vector<int>OccuringArray;
        int MaxElement=A[0],MinElement=A[0];
        for(unsigned int i=0;i<A.size();i++)
        {
            if(A[i]>MaxElement)
            {
                MaxElement=A[i];
            }
            else
            {
                if(A[i]<MinElement)
                {
                    MinElement=A[i];
                }
            }
        }
        for(int i=MinElement;i<MaxElement+1;i++)
        {
            OccuringArray.push_back(0);
        }
        for(unsigned int i=0;i<A.size();i++)
        {
            OccuringArray[A[i]-MinElement]=1;
        }
        for(unsigned int i=0;i<OccuringArray.size();i++)
        {
            if(OccuringArray[i]==1)
            {
                NumberOfDistinctValues++;
            }
        }
    }
    return NumberOfDistinctValues;
}

