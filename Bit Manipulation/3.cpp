// Bit Difference
// Function to find number of bits needed to be flipped to convert A to B
// https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1


class Solution{
    public:
    int countBitsFlip(int a, int b){
        
        return __builtin_popcount(a ^ b);
    }
};