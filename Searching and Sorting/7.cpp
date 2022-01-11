// Find Missing And Repeating
// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#

#include<bits/stdc++.h>
using namespace std;

class GoodSolution
{
    /* The output of this function is stored at
    *x and *y */
    void getTwoElements(int arr[], int n,
    int* x, int* y)
    {
    /* Will hold xor of all elements
    and numbers from 1 to n */
    int xor1;

    /* Will have only single set bit of xor1 */
    int set_bit_no;

    int i;
    *x = 0;
    *y = 0;

    xor1 = arr[0];

    /* Get the xor of all array elements */
    for (i = 1; i < n; i++)
    xor1 = xor1 ^ arr[i];

    /* XOR the previous result with numbers
    from 1 to n*/
    for (i = 1; i <= n; i++)
    xor1 = xor1 ^ i;

    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);

    /* Now divide elements into two
    sets by comparing a rightmost set
    bit of xor1 with the bit at the same
    position in each element. Also,
    get XORs of two sets. The two
    XORs are the output elements.
    The following two for loops
    serve the purpose */
    for (i = 0; i < n; i++) {
    if (arr[i] & set_bit_no)
    /* arr[i] belongs to first set */
    *x = *x ^ arr[i];

    else
    /* arr[i] belongs to second set*/
    *y = *y ^ arr[i];
    }
    for (i = 1; i <= n; i++) {
    if (i & set_bit_no)
    /* i belongs to first set */
    *x = *x ^ i;

    else
    /* i belongs to second set*/
    *y = *y ^ i;
    }

    /* *x and *y hold the desired
    output elements */
    }
};

class EfficientSolution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int* res = new int[2];
        int sum = 0;
        int temp = 0;
        
        for(int i = 0; i < n; i++)
        {
            temp = abs(arr[i]) - 1;
            sum += temp - i;
            
            if(arr[temp] < 0)
                res[0] = temp+1;
            else
                arr[temp] *= -1;
        }
        
        res[1] = res[0] - sum;
        
        // arr[0] = res[0];
        // arr[1] = res[1];
        
        return res;
        
    }
};


class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        for(int i = 0; i < n; i++)
        {
            int temp = abs(arr[i])-1;
            arr[temp] *= -1;
        }
        vector<int> a;
        for(int i = 0; i < n; i++)
        {
            // cout << arr[i] << " ";
            if(arr[i] > 0)
                a.push_back(i+1);
        }
        // cout <<endl;
        for(int i = 0; i < n; i++)
        {
            if(abs(arr[i]) == a[0])
            {
                arr[0] = a[0];
                arr[1] = a[1];
                return arr;
            }
            if(abs(arr[i]) == a[1])
            {
                arr[0] = a[1];
                arr[1] = a[0];
                return arr;
            }
        }
    }
};