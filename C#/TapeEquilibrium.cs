private static int solution(int[] A)
        {
            int minimalDifference = 0, difference = 0, sumOfAllElements = 0;
            for (int i = 0; i < A.Length; i++)
            {
                sumOfAllElements += A[i];
            }
            int leftSide = 0, rightSide = sumOfAllElements;
            for (int i = 0; i < A.Length; i++)
            {
                leftSide += A[i];
                rightSide -= A[i];
                difference = Math.Abs(leftSide - rightSide);
                if ((i == 0)||(difference<minimalDifference))
                {
                    minimalDifference = difference;
                }
            }
            return minimalDifference;
        }