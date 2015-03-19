#include <cstdlib>
#include <cmath>

using namespace std;

int solution(int X, int Y, int D) {
    int jumpCount=ceil((double)(Y-X)/(double)D);
    return jumpCount;
}