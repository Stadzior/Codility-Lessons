using System;
// you can also use other imports, for example:
// using System.Collections.Generic;

// you can use Console.WriteLine for debugging purposes, e.g.
// Console.WriteLine("this is a debug message");

class Solution {
   public int solution(int X, int Y, int D)
        {
            var jumpCount = (int) Math.Ceiling(Convert.ToDouble(Y-X)/Convert.ToDouble(D));
            return jumpCount;
        }
}
