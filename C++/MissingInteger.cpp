using namespace std;

int solution(vector<int> &A) {
    unsigned int minPositiveMissingInteger=A.size()+1;
    bool *OccuringArray = new bool[A.size()];
    uninitialized_fill_n(OccuringArray,A.size(),0);
    for(unsigned int i=0;i<A.size();i++)
    {
        if((A[i]>0)&&(A[i]<A.size()+1))
        {
            OccuringArray[A[i]-1]=1;
        }
    }
    for(unsigned int i=0;i<A.size();i++)
    {
        if(OccuringArray[i]==0)
        {
            minPositiveMissingInteger=i+1;
            break;
        }
    }
    return minPositiveMissingInteger;
    delete []OccuringArray;
}
