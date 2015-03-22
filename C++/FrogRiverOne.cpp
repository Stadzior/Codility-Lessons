

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;

int solution(int X, vector<int> &A) {
int resultPosition=-1;
if(X<A.size()+1)
{    
    for(unsigned int i=0;i<A.size();i++)				  //Looking for a leaf on destination position.
    {
        if(A[i]==X)
        {
            resultPosition=i;
            break;
        }
    }
    if(resultPosition!=-1)
    {
    	if((A.size()!=1)||(resultPosition!=0))
    	{
        bool *OccuringArray=new bool[X-1];
        uninitialized_fill_n(OccuringArray,X-1,0);
        for(int i=0;i<resultPosition;i++)      			 //Detecting an Occuring of leaves.
        {   
            if(((A[i]>0)&&(A[i]<X))||(A[i]==1)) 
            {
                OccuringArray[A[i]-1]=true;
            }
        }                                           
        bool PathIsComplete=true;
        vector<int>GapsArray;
        for(int i=0;i<X-1;i++)       					//Looking for gaps in path.
        {
            if(OccuringArray[i]==0)
            {
                GapsArray.push_back(i);
                PathIsComplete=false;
            }
        }
        delete []OccuringArray;
        if(!PathIsComplete)
        {
        	for(unsigned int i=resultPosition+1;i<A.size();i++)           //Looking for complete path.
        	{
            	for(unsigned int j=0;j<GapsArray.size();j++)
            	{
                    if(A[i]==GapsArray[j]+1)
                    {
                    	GapsArray.erase(GapsArray.begin()+j);
                    }
            	}
            	if(GapsArray.size()==0)
            	{
    	        	PathIsComplete=true;
    	        	resultPosition=i;
    	        	break;
    	        }
        	}
        }
        if(!PathIsComplete)
        {
            resultPosition=-1;
        }
    	}
    }
}
return resultPosition;
}


