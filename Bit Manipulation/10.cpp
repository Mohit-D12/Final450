// Power Set using bits
// https://practice.geeksforgeeks.org/problems/power-set4302/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> result;
		    int n = s.length();
		    int size = 1 << n;
		    
		    for(int i = 1; i < size; i++)
		    {
		        result.push_back("");
		        int mask = size>>1;
		        
		        for(int j = 0; j < n; j++)
		        {
		            if(mask&i)
		                result[i-1].push_back(s[j]);
		            mask >>= 1;
		        }
		  
		    }
		
		    sort(result.begin(), result.end());
		    return result;
		}
		
};