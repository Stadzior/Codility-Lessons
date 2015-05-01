//Naive implementation with time complexity O(n^2)

int solution(vector<int> &A) {
    int startPosMinAvgSlice=-1;
    double SliceAverage=-1,MinimalSliceAverage=-1;
    for(int i=0;i<A.size();i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            SliceAverage=0;
            for(int k=j;k>i-1;k--)
            {
                SliceAverage+=A[k];          
            }
            SliceAverage/=(j-i+1);
            if(((i==0)&&(j==i+1))||(SliceAverage<MinimalSliceAverage))
            {
                MinimalSliceAverage=SliceAverage;
                // cout<<i<<' '<<j<<' '<<SliceAverage<<endl;
                startPosMinAvgSlice=i;
            }
        }
    }
    return startPosMinAvgSlice;
}

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
double CalculateSliceAverage(vector<int> &A,int startPos,int endPos)
{
    unsigned int SliceLength=endPos-startPos+1,SliceElementsSum=0;
    for(int i=endPos;i>(startPos-1);i--)
    {
        SliceElementsSum+=A[i];
    }
    return SliceElementsSum/SliceLength;
}

int solution(vector<int> &A) {
    int startPosMinAvgSlice=-1;
    double SliceAverage=-1, MinimalSliceAverage=-1;
    for(int i=0;i<A.size()-1;i++)
    {
            if(i==0)
            {
                MinimalSliceAverage=CalculateSliceAverage(A,i,i+1);
                startPosMinAvgSlice=i;
            }
            else
            {
                
            }
        for(int j=i+1;j<A.size();j++)
        {
            SliceAverage=0;
            for(int k=j;k>i-1;k--)
            {
                SliceAverage+=A[k];          
            }
            SliceAverage/=(j-i+1);
           // cout<<i<<' '<<j<<' '<<SliceAverage<<endl;
        }
    //    cout<<endl;
    }
    return startPosMinAvgSlice;
}

