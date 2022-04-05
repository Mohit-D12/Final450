// k largest elements
// https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1#

#include<bits/stdc++.h>
using namespace std;

class Solution_HEAP{
    
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    
	    vector<int> result(arr, arr+k);
	    make_heap(result.begin(), result.end(), greater<int>());
	    
	    for(int i = k; i < n; i++) {
	        
	        if(result[0] < arr[i]) {
	            
	            pop_heap(result.begin(), result.end(), greater<int>());
	            result[k - 1] = arr[i];
	            push_heap(result.begin(), result.end(), greater<int>());
	        }
	    }
	    
	    sort_heap(result.begin(), result.end(), greater<int>());
	    return result;
	    
	}

};

class Solution_PRIORITY_QUEUE{
    
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    
	    priority_queue<int, vector<int>, greater<int>> q;
	    
	    for(int i = 0; i < n; i++) {
	        
	        if(q.size() < k)
	            q.push(arr[i]);
	        else if(q.top() < arr[i]) {
	            
	            q.pop();
	            q.push(arr[i]);
	        }
	    }
	    
	    vector<int> result(k);
	    while(q.size()) {
	        
	        result[--k] = q.top();
	        q.pop();
	    }
	    
	    return result;
	}

};