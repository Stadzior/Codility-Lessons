// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#define MIN_PRIME 2

bool isPrime(unsigned int input)
{
    bool flag=true;
    unsigned int i=2;
    do{
        if(input%i)
        {
            flag=false;
            i=input;
        }
        else
        {
            i++;
        }
    }while(i<input);
    return flag;
}

bool isSemiprime(unsigned int input)
{
    bool flag=false;
    unsigned int i=MIN_PRIME;
    do
    {
        if (isPrime(i)&&!(input%i)&&isPrime(input/i))
        {
            flag=true;
            i=input;
        }
        else
        {
            i++;
        }
    }while(i<input);
    return flag;
}

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    vector<int>QueriesAnswers;
    for(unsigned int i=0;i<P.size();i++)
    {
        QueriesAnswers.push_back(0);
    }
    for(unsigned int i=0;i<P.size();i++)
    {
        if(P[i]<=Q[i])
        {
            for(unsigned int j=P[i];j<Q[i]+1;j++)
            {
                if(isSemiprime(j))
                {
                        QueriesAnswers[i]++;
                }
            }
        }
    }
    return QueriesAnswers;
}

