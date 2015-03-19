using namespace std;

int solution(vector<int> &A) 
{
    unsigned int isPermutation=1,OccuringArray[A.size()],maxElement=0;
    for(unsigned int i=0;i<A.size();i++)
    {
        if((i==0)||(A[i]>maxElement))
        {
            maxElement=A[i];
        }
    }
    uninitialized_fill_n(OccuringArray,A.size(),0);
    for(unsigned i=0;i<A.size();i++)
    {
        if(maxElement>A.size())
        {
            isPermutation=0;
            break;
        }
        OccuringArray[A[i]-1]=1;
    }
    if(isPermutation==1)
    {
        for(unsigned int i=0;i<A.size();i++)
        {
            if(OccuringArray[i]==0)
            {
                isPermutation=0;
                break;
            }
        }
    }
    return isPermutation;
}
