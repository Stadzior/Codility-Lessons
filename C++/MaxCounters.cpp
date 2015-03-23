// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
void increase(vector<int> &inputVector,int index)
{
    inputVector[index]++;
}

void MaxCounter(vector<int> &inputVector,int MaximumValue)
{
    for(unsigned int i=0;i<inputVector.size();i++)
    {
        inputVector[i]=MaximumValue;
    }
}

using namespace std;

vector<int> solution(int N, vector<int> &A) {
    vector<int>countersVector;
    int maxValueOfCountersVector=0;
    for(int i=0;i<N;i++)
    {
        countersVector.push_back(0);
    }
    for(unsigned int i=0;i<A.size();i++)
    {
        if(((A[i]>0)&&(A[i]<N))||(A[i]==1))
        {
            increase(countersVector,A[i]-1);
            if(countersVector[A[i]-1]>maxValueOfCountersVector)
            {
                maxValueOfCountersVector=countersVector[A[i]-1];
            }
        }
        if(A[i]==(N+1))
        {
            MaxCounter(countersVector,maxValueOfCountersVector);
        }
    }
    return countersVector;
}
