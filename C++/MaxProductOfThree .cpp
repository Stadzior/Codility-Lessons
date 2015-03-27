//Attempt #1 Correctness: 50% Performance: 60%

#define TRIPLET 3
#include <cmath>
using namespace std;

int solution(vector<int> &A) {
    int resultProduct=0;
    if(A.size()==3)
    {
        resultProduct=A[0]*A[1]*A[2];
    }
    else
    {
        vector<int>MaxArray;
        for(int i=0;i<TRIPLET;i++)
        {
            MaxArray.push_back(A[0]);
        }
        unsigned int NegativeCount=0;
        for(unsigned int i=0;i<A.size();i++)
        {
            if((abs(A[i])>abs(MaxArray[0]))||((A[i]>0)&&(A[i]==-MaxArray[0])))
            {
                MaxArray[2]=MaxArray[1];
                MaxArray[1]=MaxArray[0];
                MaxArray[0]=A[i];
            }
            else 
            {
                if((abs(A[i])>abs(MaxArray[1]))||((A[i]>0)&&(A[i]==-MaxArray[1])))
                {
                    MaxArray[2]=MaxArray[1];
                    MaxArray[1]=A[i];
                }
                else
                {
                    if((abs(A[i])>abs(MaxArray[2]))||((A[i]>0)&&(A[i]==-MaxArray[2])))
                    {
                        MaxArray[2]=A[i];
                    }
                }
            }
            if(A[i]<0)
            {
                NegativeCount++;
            }
        }
        if(NegativeCount<A.size())
        {
            vector<bool>MaxArraySign;
            NegativeCount=0;
            for(int i=0;i<TRIPLET;i++)
            {
                if(MaxArray[i]<0)
                {
                    MaxArraySign.push_back(false);
                    NegativeCount++;
                }
                else
                {
                    MaxArraySign.push_back(true);
                }
            }
            if(NegativeCount%2==0)
            {
                resultProduct=MaxArray[0]*MaxArray[1]*MaxArray[2];
            }
            else
            {
                int MaximumOfTheRest=0;
                for(unsigned int i=0;i<A.size();i++)
                {
                    if((A[i]!=MaxArray[0])&&(A[i]!=MaxArray[1])&&(A[i]!=MaxArray[2]))
                    {
                        if(i==0)
                        {
                            MaximumOfTheRest=A[i];
                        }
                        else
                        {
                            if(MaximumOfTheRest<A[i])
                            {
                                MaximumOfTheRest=A[i];
                            }
                        }
                    }
                }
                MaxArray[2]=MaximumOfTheRest;
                resultProduct=MaxArray[0]*MaxArray[1]*MaxArray[2];
            }
        }
        else
        {
            for(unsigned int i=0;i<A.size();i++)
            {
                if(A[i]>MaxArray[0])
                {
                    MaxArray[2]=MaxArray[1];
                    MaxArray[1]=MaxArray[0];
                    MaxArray[0]=A[i];
                }
                else 
                {
                    if(A[i]>MaxArray[1])
                    {
                        MaxArray[2]=MaxArray[1];
                        MaxArray[1]=A[i];
                    }
                    else
                    {
                        if(A[i]>MaxArray[2])
                        {
                            MaxArray[2]=A[i];
                        }
                    }
                }
            }
            resultProduct=MaxArray[0]*MaxArray[1]*MaxArray[2];
        }
    }
    return resultProduct;
}

//Attempt #2 C: 100% P: 100%

#define TRIPLET 3
#define NUMBER_OF_POTENTIAL_NEGATIVE_MEMBERS 2
using namespace std;

void InsertionSort(vector<int>&Vector)
{
    int temp;
    for(unsigned int i=0;i<Vector.size();i++)
    {
       for(unsigned int j=0;j<Vector.size();j++)
       {
           if(Vector[i]>Vector[j])
           {
               temp=Vector[i];
               Vector[i]=Vector[j];
               Vector[j]=temp;
           }
       }
    }
}

int solution(vector<int> &A) {
    int resultProduct;
    unsigned int NegativeCount=0;
    if(A.size()==3)
    {
        resultProduct=A[0]*A[1]*A[2];
    }
    else
    {
        if(A.size()==4)
        {
            resultProduct=A[0]*A[1]*A[2];
            for(unsigned int i=0;i<(A.size()/2);i++)
            {
                for(unsigned int j=i+1;j<(A.size()/2)+1;j++)
                {
                    for(unsigned int k=j+1;k<A.size();k++)
                    {
                        if(resultProduct<A[i]*A[j]*A[k])
                        {
                            resultProduct=A[i]*A[j]*A[k];
                        }
                    }
                }
            }
        }
        else
        {
            for(unsigned int i=0;i<A.size();i++)
            {
                if(A[i]<0)
                {
                    NegativeCount++;
                }
            }
            if(NegativeCount>A.size()-1)
            {
                int tempMin=A[0];
                vector<int>TripletVector;
                for(unsigned int i=0;i<A.size();i++)
                {
                    if(A[i]<tempMin)
                    {
                        tempMin=A[i];
                    }
                }
                for(unsigned int i=0;i<TRIPLET;i++)
                {
                    TripletVector.push_back(tempMin);
                }
                for(unsigned int i=0;i<A.size();i++)
                {
                    if(A[i]>TripletVector[0])
                    {
                        TripletVector[2]=TripletVector[1];
                        TripletVector[1]=TripletVector[0];
                        TripletVector[0]=A[i];
                    }
                    else 
                    {
                        if(A[i]>TripletVector[1])
                        {
                            TripletVector[2]=TripletVector[1];
                            TripletVector[1]=A[i];
                        }
                        else
                        {
                            if(A[i]>TripletVector[2])
                            {
                                TripletVector[2]=A[i];
                            }
                        }
                    }    
                }
                resultProduct=TripletVector[0]*TripletVector[1]*TripletVector[2];
            }
            else
            {
                vector<int>TripletVector;
                for(unsigned int i=0;i<TRIPLET+NUMBER_OF_POTENTIAL_NEGATIVE_MEMBERS;i++)
                {
                    TripletVector.push_back(A[i]);
                }
                InsertionSort(TripletVector);
                for(unsigned int i=TripletVector.size();i<A.size();i++)
                {
                    if(A[i]>TripletVector[0])
                    {
                        TripletVector[2]=TripletVector[1];
                        TripletVector[1]=TripletVector[0];
                        TripletVector[0]=A[i];
                    }
                    else 
                    {
                        if(A[i]>TripletVector[1])
                        {
                            TripletVector[2]=TripletVector[1];
                            TripletVector[1]=A[i];
                        }
                        else
                        {
                            if(A[i]>TripletVector[2])
                            {
                                TripletVector[2]=A[i];
                            }
                            else
                            {
                                if(A[i]<TripletVector[4])
                                {
                                    TripletVector[3]=TripletVector[4];
                                    TripletVector[4]=A[i];
                                }
                                else
                                {
                                    if(A[i]<TripletVector[3])
                                    {
                                        TripletVector[3]=A[i];
                                    }
                                }
                            }
                        }
                    }
                }
                if(TripletVector[1]*TripletVector[2]>TripletVector[3]*TripletVector[4])
                {
                    resultProduct=TripletVector[0]*TripletVector[1]*TripletVector[2];
                }
                else
                {
                    resultProduct=TripletVector[0]*TripletVector[3]*TripletVector[4];
                }
            }    
        }
    }
    return resultProduct;
}

