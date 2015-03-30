//Correctness: 100% Performance: 100%

#include <stack>
#include <cstdlib>
using namespace std;

int solution(string &S) {
   int Status=0;
   stack<char>OpenedBracketsStack;
   int UnopenedBracketsCount=0;
   for(unsigned int i=0;i<S.length();i++)
   {
       if(S[i]=='(')
       {
           OpenedBracketsStack.push(S[i]);
       }
       else
       {
           if(!OpenedBracketsStack.empty())
           {
                if(S[i]==')')
                {
                    UnopenedBracketsCount++;
                    if((S[i]==')')&&(OpenedBracketsStack.top()=='('))
                    {
                        OpenedBracketsStack.pop();
                        UnopenedBracketsCount--;
                    }
                }
            }
            else
            {
                UnopenedBracketsCount++;
                break;
            }
        }
    }    
   if((OpenedBracketsStack.empty())&&UnopenedBracketsCount==0)
   {
       Status=1;
   }
   return Status;
}
