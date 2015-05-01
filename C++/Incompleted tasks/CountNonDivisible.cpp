//Naive solution C:100% P:0%

vector<int> solution(vector<int> &A) {
    vector<int>NonDivisorsAmount;
    for(unsigned int i=0;i<A.size();i++)
    {
        NonDivisorsAmount.push_back(0);
    }
    for(unsigned int i=0;i<A.size();i++)
    {
        for(unsigned int j=0;j<A.size();j++)
        {
            if((j!=i)&&(A[i]%A[j]))
            {
                NonDivisorsAmount[i]++;
            }
        }
    }
    return NonDivisorsAmount;
}
