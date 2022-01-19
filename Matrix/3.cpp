// Median in a row-wise sorted Matrix
// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#

#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int median(vector<vector<int>> &arr, int r, int c){
        // code here   
        int s = arr[0][0], e = arr[0][0];
        int mid;
        for(int i = 0; i < r; i++)
        {
            s = min(s, arr[i][0]);
            e = max(e, arr[i][c-1]);
        }
        int req = (r * c + 1) / 2;
        
        while (s < e)
        {
            mid = s + (e - s)/2;
            int count = 0;
            for (int i = 0; i < r; i++)
                count += upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin();
              
            if (count < req)
                s = mid + 1;
            else
                e = mid;
        }
        return s;
        
    }
};