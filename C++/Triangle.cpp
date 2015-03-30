//I was unable to measure the score because of broken tests from Codility.com
//No matter what output there was , the score always was 0%

using namespace std;

void CountingSort(vector<int> &A)
{
    int MinA=A[0],MaxA=A[0];
    for(unsigned int i=0;i<A.size();i++)
    {
        if(A[i]>MaxA)
        {
            MaxA=A[i];
        }
        else
        {
            if(A[i]<MinA)
            {
                MinA=A[i];
            }
        }
    }
    vector<int>OccuringArray;
    int LoopCounter=0;
    for(int i=0;i<(MaxA-MinA+1);i++)
    {
        OccuringArray.push_back(0);
    }
    for(unsigned int i=0;i<A.size();i++)
    {
        OccuringArray[A[i]-MinA]++;
    }
    for(unsigned int i=0;i<OccuringArray.size();i++)
    {
        if(OccuringArray[i]>0)
        {
            for(int j=LoopCounter;j<OccuringArray[i]+LoopCounter;j++)
            {
                A[j]=i+MinA;
            }
            LoopCounter+=OccuringArray[i];
            OccuringArray[i]=0;
        }
    }
}

int solution(vector<int> &A) {
    int Triangular=0;
    if(A.size()>3)
    {
        CountingSort(A);
        for(unsigned int i=0;i<A.size()-2;i++)
        {
            if((A[i]<0)&&(A[i+1]<0)&&(A[i+2]<0))
            {
                if((A[i+2]+A[i+1])<A[i])
                {
                    Triangular=1;
                    break;
                }
            }
            else 
            {
                if((A[i]+A[i+1])>A[i+2])
                {
                    Triangular=1;
                    break;
                }
            }
        }
    }
    return Triangular;
}

