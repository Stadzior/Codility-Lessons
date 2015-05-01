// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <stack>

using namespace std;
void ClearStack(stack<int> &CollisionStack)
{
    while(!CollisionStack.empty())
   	{
   	    CollisionStack.pop();
   	}
}

void Elimination(int DownstreamSwimmerId,vector<int> &A, vector<int> &B,stack<int> &CollisionStack)
{
	unsigned int ColStackPrevSize=CollisionStack.size(),DeadCount=0;
	for(unsigned int i=0;i<ColStackPrevSize;i++)
	{
		if(A[DownstreamSwimmerId]>A[CollisionStack.front()-DeadCount])
		{
			A.erase(A.begin()+CollisionStack.front()-DeadCount);
			B.erase(B.begin()+CollisionStack.front()-DeadCount);
			CollisionStack.pop();
			DeadCount++;
		}
		else
		{
			if(A[DownstreamSwimmerId]<A[CollisionStack.front()-DeadCount])
			{
				A.erase(A.begin()+DownstreamSwimmerId);
				B.erase(B.begin()+DownstreamSwimmerId);
				break;
			}
		}
	}
}

int solution(vector<int> &A, vector<int> &B) {
    stack<int>CollisionStack;
    int PrevI=A.size-1;
    for(int i=A.size()-2;i>-1;i--)
   	{ 
   		if(B[i])
    	{
    		for(unsigned int j=PrevI;j>i;j--)
    		{
   				if(!B[j])
    			{
    				CollisionStack.push(j);
    			}
    		}
    		Elimination(i,A,B,CollisionStack);
    		ClearStack(CollisionStack);
    		PrevI=i;
    	}
	}	
    return A.size();
}

