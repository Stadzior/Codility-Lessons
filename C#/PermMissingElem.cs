using System;
// you can also use other imports, for example:
// using System.Collections.Generic;

// you can use Console.WriteLine for debugging purposes, e.g.
// Console.WriteLine("this is a debug message");

class Solution {
        public int solution(int[] A)
        {
            var OccuringArray=new int[A.Length+1];
            for (int i = 0; i < A.Length; i++)
            {
                OccuringArray[i] = 0;
            }
            int MissingElement = 1;
            for (int i = 0; i <A.Length; i++)
            {
                OccuringArray[A[i] - 1] = 1;
            }
            for (int i = 0; i < A.Length; i++)
            {
                if (OccuringArray[i]==0)
                {
                    MissingElement = i + 1;
                }
            }
            return MissingElement;
        }
}
