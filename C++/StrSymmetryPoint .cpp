// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <stack>
#include <cstdlib>
using namespace std;

int solution(string &S) {
	int Pivot=-1;
	if(S.length()%2!=0)
	{
		Pivot=S.length()/2;
		if(Pivot>0)
		{
			for(int i=0;i<Pivot+1;i++)
			{
				if(S[Pivot+i]!=S[Pivot-i])
				{
					Pivot=-1;
					break;
				}
			}
		}
	}
	return Pivot;
}
