// Row with max 1s
// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int r = 0;
	    int j = m;
	    for(int i = 0; i < n; i++)
	    {
	        if (j > 0 && arr[i][j-1] == 1)
	            r = i;
	        while( j > 0 && arr[i][j-1] == 1)
	            j--;
	        
	        if (j == 0)
	            break;
	    }
	    if (j == m)
	        return -1;
	    return r;
	}

};