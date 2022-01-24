// Sort an array of 0s, 1s and 2s
// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // coode here 
        int i = 0;
        int j = n - 1;
        
        for(int x = 0; x <= j;)
        {
            if (a[x] == 0)
            {
                swap(a[i], a[x]);
                i++;
            }
            if(a[x] == 2)
            {
                swap(a[j], a[x]);
                j--;
            }
            if(x < i || a[x] == 1)
                x++;
        }
    
    }
    

    void sort012(int a[], int arr_size)
    {
        int lo = 0;
        int hi = arr_size - 1;
        int mid = 0;

        while (mid <= hi) {
            switch (a[mid]) {

            case 0:
                swap(a[lo++], a[mid++]);
                break;

            case 1:
                mid++;
                break;

            case 2:
                swap(a[mid], a[hi--]);
                break;
            }
        }
    }
};