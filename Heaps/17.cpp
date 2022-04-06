// Reorganize String (same as 9.cpp)
// https://leetcode.com/problems/reorganize-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        
        vector<int> count(26);
        priority_queue<pair<int, char>> q;
        
        string result = "";
        
        for(char c: s)
            count[c - 'a']++;
        
        for(int i = 0; i < 26; i++) {
            
            if(count[i])
                q.push({count[i], 'a' + i});
        }
        
        pair<int, char> a, b;
        
        while(q.size()) {
            
            a = q.top();
            q.pop();
            
            result += a.second;
            
            if(q.size() == 0) {
                
                if(a.first == 1)
                    break;
                
                return "";
            }
            
            b = q.top();
            q.pop();
            
            result += b.second;
            
            if(--(a.first))
                q.push(a);
            if(--(b.first))
                q.push(b);
        }
        
        return result;
    }
};