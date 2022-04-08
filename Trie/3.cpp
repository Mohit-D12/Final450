// Word break
// https://practice.geeksforgeeks.org/problems/d857113143f69fab217cf5dab978535542f3cbb1/1/

#include<bits/stdc++.h>
using namespace std;

class Node {
    
public:
    Node* val[26];
    bool is_terminal;
    
    Node() {
        
        for(int i = 0; i < 26; i++)
            this->val[i] = NULL;
            
        this->is_terminal = false;
    }
    
    int count_children() {
        
        int count = 0;
        
        for(int i = 0; i < 26; i++) {
            
            if(val[i])
                count++;
        }
        
        return count;
    }
};
    
class Trie {
  
  public:  
    Node* head;
    
    Trie() {
        
        head = new Node();
    }
    
    void insert(string word) {
        
        Node* curr = head;
        
        for(char ch: word) {
            
            if(curr->val[ch - 'a'] == NULL)
                curr->val[ch - 'a'] = new Node();
            
            curr = curr->val[ch - 'a'];
        }
        
        curr->is_terminal = true;
    }
    
    bool search(string word) {
        
        Node* curr = head;
        
        for(char ch: word) {
            
            if(curr->val[ch - 'a'] == NULL)
                curr->val[ch - 'a'] = new Node();
        
            curr = curr->val[ch - 'a'];
        }
        
        return curr->is_terminal;
    }
};


class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    int wordBreak(string A, vector<string> &B) {
        
        //code here
        int n = A.length();
        vector<bool> dp(n + 1, false);      // dp[i] denotes if word A[0:i-1] (inclusive) can be broken or not
        
        Trie* t = new Trie();
        for(string k : B)
            t->insert(k);
        
        dp[0] = true;
        
        for(int i = 1; i <= n; i++) {
            
            for(int j = i; j >= 0; j--) {
                
                if(dp[j] && t->search(A.substr(j, i - j))) {
                    
                    dp[i] = true;
                    break;
                }
            }
        }
        
        if(dp[n])
            return 1;
        return 0;
    }
};