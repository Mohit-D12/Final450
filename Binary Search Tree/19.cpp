// Validate preorder of bt
// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    int index;
    
    bool validate(string& s) {
        
        if(index >= s.length())
            return false;
        
        if(s[index] == '#') {
            
            index += 2;
            return true;
        }
        
        while(index < s.length() && s[index] != ',')
            index++;
        
        index++;
        if(!validate(s))
            return false;
        
        return validate(s);
    }
    
public:
    bool isValidSerialization(string preorder) {
        
        index = 0;
        return validate(preorder) && (index >= preorder.length());
    }
};