// Find All Four Sum Numbers
// https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1


#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        
        // Your code goes here
        sort(arr.begin(), arr.end());
        int n = arr.size();

        vector<vector<int>> result;
        int sum = 0;
        
        for(int i = 0; i < n-3; i++)
        {

            //removing duplicates
            if(i > 0 and arr[i] == arr[i-1])
                continue;

            for(int j = i+1; j < n-2; j++)
            {   
                
                //removing duplicates
                if(j > i+1 and arr[j] == arr[j-1])
                    continue;

                sum = k - arr[i] - arr[j];
                
                int x = j + 1;
                int y = n-1;
                while (x < y)
                {
                    if(arr[x] + arr[y] > sum)
                        y--;

                    else if(arr[x] + arr[y] < sum)
                        x++;

                    else
                    {
                        vector<int> r = {arr[i], arr[j], arr[x], arr[y]};
                        result.push_back(r);
                        x++; y--;


                        //removing duplicates
                        while(x < y && arr[x] == arr[x-1])
                            x++;
                        while(x < y && arr[y] == arr[y+1])
                            y--;                        
                        
                    }
                }
            }
        }
        return result;
    }
};