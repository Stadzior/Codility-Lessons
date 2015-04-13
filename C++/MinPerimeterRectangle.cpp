// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    int MinimalPerimeter;
    if(!N)
    {
        MinimalPerimeter=0;
    }
    else
    {
        int Width=1,Height=N/Width;
        MinimalPerimeter=2*(Width+Height);
        do{
            Width++;
            Height=N/Width;
            if((2*(Width+Height)<MinimalPerimeter)&&(Width*Height==N))
            {
                MinimalPerimeter=2*(Width+Height);
            }
        }while(Height-Width>1);
    }
    return MinimalPerimeter;
}
