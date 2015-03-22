// Naive solution , with time complexity O(n^2)

int solution(vector<int> &A) {
    vector<int>P,Q;
    for(unsigned int i=0;i<A.size();i++)
    {
        if(A[i]==0)
        {
            P.push_back(i);
        }
        else
        {
            Q.push_back(i);
        }
    }
    int passingPairsCount=0;
    for(unsigned int i=0;i<P.size();i++)
    {
        for(unsigned int j=0;j<Q.size();j++)
        {
            if(P[i]<Q[j])
            {
                if(passingPairsCount<100000000)
                {
                passingPairsCount++;
                }
                else
                {
                    passingPairsCount=-1;
                    break;
                }
            }
            if(passingPairsCount==-1)
            {
                break;
            }
        }
    }
    return passingPairsCount;
}

//////////////////////////////////////////////////////////////////////////

//Effective solution with time complexity O(n)

int solution(vector<int> &A) {
    vector<int>P;
    for(unsigned int i=0;i<A.size();i++)
    {
        if(A[i]==0)
        {
            P.push_back(i);
        }
    }
    int passingPairsCount=0;
    int QCarsPassedByEachPCar=P.size();
    for(unsigned int i=0;i<P.size();i++)
    {
    	if(passingPairsCount<1000000000)
    	{
        passingPairsCount+=A.size()-P[i]-QCarsPassedByEachPCar;
        QCarsPassedByEachPCar--;
    	}
    	else
		{
			passingPairsCount=-1;
			break;
    	}
    }
    return passingPairsCount;
}

