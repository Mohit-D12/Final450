// Count Squares
// https://practice.geeksforgeeks.org/problems/count-squares3649/1

class Solution {
  public:
    int countSquares(int N) 
    {
        // code here
        int s = 1;
        int e = N-1;
        int result = 0;
        int mid = s + (e - s)/2;
        
        while(s <= e)
        {
            if ((long long int)mid * mid < N)
            {
                result = mid;
                s = mid + 1;
            }
            else
                e = mid - 1;
            
            mid = s + (e - s)/2;
        }
        
        return result;
    }
};