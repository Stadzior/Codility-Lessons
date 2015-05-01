#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	srand(time(0));
	FILE *pFile;
  	pFile = fopen ("myfile.txt","w");
  	if (pFile!=NULL)
	{
  		fprintf (pFile,"([");
  		for(int i=0;i<99999;i++)
  		{
    		fprintf (pFile,"%i,",rand()%10+1);
		}
		fprintf(pFile,"%i],[",rand()%10+1);
		for(int i=0;i<99999;i++)
		{
    		fprintf (pFile,"%i,",rand()%2);
		}
		fprintf(pFile,"%i])",rand()%2);
   		fclose (pFile);
	}
}
