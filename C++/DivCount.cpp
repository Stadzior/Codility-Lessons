// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) {
    int DivCount=0;
    DivCount=(B/K)-(A/K);
    if(A%K==0)
    {
        DivCount++;
    }
    return DivCount;
}
