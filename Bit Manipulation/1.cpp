// Number of 1 Bits
// https://practice.geeksforgeeks.org/problems/set-bits0143/1#


#include <bits/stdc++.h>
using namespace std;

int n = 10;


//built-in method
    int count = __builtin_popcount(n);

// Brian Kernighan's Algorithm
    unsigned int countSetBits3(int n)
    {
        unsigned int count = 0;
        while (n) 
        {
            n &= (n - 1);
            count++;
        }
        return count;
    }

// Lookup Tableint BitsSetTable256[256];

    int BitsSetTable256[256];
    
    void initialize()
    {
        BitsSetTable256[0] = 0;
        for (int i = 0; i < 256; i++)
        {
            BitsSetTable256[i] = (i & 1) +
            BitsSetTable256[i / 2];
        }
    }

    int countSetBits(int n)
    {
        return (BitsSetTable256[n & 0xff] +
        BitsSetTable256[(n >> 8) & 0xff] +
        BitsSetTable256[(n >> 16) & 0xff] +
        BitsSetTable256[n >> 24]);
    }

// Nibble Count
    int num_to_bits[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };

    /* Recursively get nibble of a given number and map them in the array */
    unsigned int countSetBitsRec(unsigned int num)
    {
        int nibble = 0;
        if (0 == num)
            return num_to_bits[0];

        // Find last nibble
        nibble = num & 0xf;

        // Use pre-stored values to find count in last nibble plus recursively add remaining nibbles.
        return num_to_bits[nibble] + countSetBitsRec(num >> 4);
    }
