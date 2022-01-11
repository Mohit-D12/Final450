// Square a number using bitwise operators
// https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/

#include <bits/stdc++.h>
using namespace std;
 

// Apprpach1 : For a given number `num` we get square of it by multiplying number as `num * num`. Now write one of `num` in square `num * num` in terms of power of `2`. Check below examples.

int square(int num)
{
    // handle negative input
    if (num < 0) num = -num;
 
    // Initialize result
    int result = 0, times = num;
 
    while (times > 0)
    {
        int possibleShifts = 0, currTimes = 1;
 
        while ((currTimes << 1) <= times)
        {
            currTimes = currTimes << 1;
            ++possibleShifts;
        }
 
        result = result + (num << possibleShifts);
        times = times - currTimes;
    }
 
    return result;
}

/* 
    Approach 2:
        If n is even, it can be written as
        n = 2*x 
        n2 = (2*x)^2 = 4*x^2

        If n is odd, it can be written as 
        n = 2*x + 1
        n2 = (2*x + 1)^2 = 4*x^2 + 4*x + 1
*/

int square(int n)
{
    // Base case
    if (n == 0)
        return 0;
 
    // Handle negative number
    if (n < 0)
        n = -n;
 
    // Get floor(n/2) using right shift
    int x = n >> 1;
 
    // If n is odd
    if (n & 1)
        return ((square(x) << 2) + (x << 2) + 1);
    else // If n is even
        return (square(x) << 2);
}