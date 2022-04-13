// first non repeating value in a stream
// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    
		    queue<char> q;
		    unordered_map<char, int> repeating;
		    
		    string result = "";
		    
		    for(char c: A) {
		        
		        q.push(c);
		        repeating[c]++;
		        
		        while(q.size() && repeating[q.front()] > 1)
		            q.pop();
		          
		        if(q.size())
		            result += q.front();
		        else 
		            result += "#";
		    }
		    
		    return result;
		}

};