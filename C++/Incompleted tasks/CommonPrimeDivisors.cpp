// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include "math.h"

bool IsPrime(int A)
{
    bool flag=true;
    int i=2;
    while((flag==true)&&(i<A))
    {
        if(A%i==0)
        {
            flag=false;
        }
        i++;
    }
    return flag;
}

bool ArePrimeDivisorsTheSame(int A,int B)
{
    bool resultFlag=true;
    vector<int> PrimeDivisorsA;
    vector<int> PrimeDivisorsB;
    int maxAB=fmax(A,B);
    for(int i=2;i<maxAB;i++)
    {
        if(IsPrime(i))
        {
            if(A%i==0)
            {
                PrimeDivisorsA.push_back(i);
            }
            
            if(B%i==0)
            {
                PrimeDivisorsB.push_back(i);
            }
        }
    }
    if(PrimeDivisorsA.size()==PrimeDivisorsB.size())
    {
        for(unsigned int i=0;i<PrimeDivisorsA.size();i++)
        {
            if(PrimeDivisorsA[i]!=PrimeDivisorsB[i])
            {
                resultFlag=false;
                break;
            }
        }
    }
    else
    {
        resultFlag=false;
    }
    return resultFlag;
}

int solution(vector<int> &A, vector<int> &B) {
    int result=0;
    for(unsigned int i=0;i<A.size();i++)
    {
        if(ArePrimeDivisorsTheSame(A[i],B[i]))
        {
            result++;
        }
    }
    return result;
}

