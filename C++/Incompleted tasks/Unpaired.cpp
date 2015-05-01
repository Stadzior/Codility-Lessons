// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    vector<int>OccuringArray;
    int UnpairedElem,MinElem=A[0],MaxElem=A[0];
    for(unsigned int i=0;i<A.size();i++)
    {
        if(A[i]>MaxElem)
        {
            MaxElem=A[i];
        }
        else
        {
            if(A[i]<MinElem)
            {
                MinElem=A[i];
            }
        }
    }
    for(int i=0;i<(MaxElem+1)-MinElem;i++)
    {
        OccuringArray.push_back(0);
    }
    for(unsigned i=0;i<A.size();i++)
    {
        OccuringArray[A[i]-MinElem]++;
    }
    for(unsigned i=0;i<OccuringArray.size();i++)
    {
        if(OccuringArray[i]==1)
        {
            UnpairedElem=i+MinElem;
        }
    }
    return UnpairedElem;
}

