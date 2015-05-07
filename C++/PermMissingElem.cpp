using namespace std;

int solution(vector<int> &A) {
    // write your code in C++11
    int OccuringArray[A.size()+1];
    for(unsigned int i=0;i<A.size()+1;i++)
    {
    OccuringArray[i]=0;
    }
    int MissingElement=1;
   for(unsigned int i=0;i<A.size();i++)
    {
        OccuringArray[A[i]-1]=1;
    }
    for(unsigned int i=0;i<A.size()+1;i++)
    {
        if(OccuringArray[i]==0)
        {
         MissingElement=i+1;   
        }
    }
    return MissingElement;
}
