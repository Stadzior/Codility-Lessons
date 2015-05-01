// Attempt #1 Correctness: 100% Performance 0%

using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    vector<int>impactFactorResult;
    int tempImpactFactor=0;
    for(unsigned int i=0;i<P.size();i++)
    {
        impactFactorResult.push_back(5);
        for(int j=Q[i];j>P[i]-1;j--)
        {
            switch(S[j])
            {
                case 'A':
                {
                    tempImpactFactor=1;
                    break;
                }
                case 'C':
                {
                    tempImpactFactor=2;
                    break;
                }
                case 'G':
                {
                    tempImpactFactor=3;
                    break;
                }
                case 'T':
                {
                    tempImpactFactor=4;
                    break;
                }
            }
            if(tempImpactFactor<impactFactorResult[i])
            {
                impactFactorResult[i]=tempImpactFactor;
            }
        }
    }
    return impactFactorResult;
}

