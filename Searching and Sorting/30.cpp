// Painter's Partition Problem
// https://www.interviewbit.com/problems/painters-partition-problem/

#include<bits/stdc++.h>
using namespace std;

bool is_possible(int m, int b, vector<int>& a, int n, long long int mx)
{
    int count = 0;
    long long int sm = 0;

    for(int i = 0; i < n; i++)
    {
        if(sm + b*a[i] > mx)
        {
            count++;
            sm = b*a[i];
        }
        else   
            sm += b*a[i];
        
        if(count == m)
            return false;
    }
    
    return true;
}

int paint(int A, int B, vector<int> &C) {
    long long int s = 0, e = 0;
    int n = C.size();
    for(int i = 0; i < n; i++)
    {
        s = max(1ll*B*C[i], s);
        e += 1ll*B*C[i];
    }

    if(A == 1)
        return e % 10000003;

    long long int res = -1;
    long long int mid = s + (e - s)/2;

    while(s <= e)
    {
        if(is_possible(A, B, C, n, mid))
        {
            res = mid % 10000003;
            e = mid - 1;
        }
        else
            s = mid + 1;
        
        mid = s + (e - s)/2;
    }

    return res % 10000003;

}