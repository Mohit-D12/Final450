// Check if 2 trees are mirror of each other when tree is given in form of adjacency list
// https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1#

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        
        if(A[0] != B[0])
            return 0;
            
        int max_index = 2*e;
        
        int i = 0, j = 0;
        
        queue<int> q;
        q.push(A[0]);
        q.push(-1);
        
        stack<pair<int, int>> s;
        pair<int, int> temp;
        
        while(q.size()) {
            
            int val = q.front();
            q.pop();
            
            if(val == -1) {
                
                if(q.empty())
                    break;
            
                while(s.size()) {
                    
                    temp = s.top();
                    
                    if(B[j] != temp.first || B[j + 1] != temp.second)
                        return 0;
                    
                    j += 2;
                    s.pop();
                }
                
                q.push(-1);
                continue;
            }
            
            while(i < max_index && A[i] == val) {
                
                q.push(A[i + 1]);
                s.push({A[i], A[i + 1]});
                
                i += 2;
            }
        }
        
        return 1;
    }
};