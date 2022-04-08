// Implement Trie
// https://leetcode.com/problems/implement-trie-prefix-tree/

#include<bits/stdc++.h>
using namespace std;

class Trie {
    class Node {
    
    public:
        Node* val[26];
        bool is_terminal;
        
        Node() {
            
            for(int i = 0; i < 26; i++)
                this->val[i] = NULL;
            this->is_terminal = false;
        }
    };
    
    Node* head;
    
public:
    Trie() {
        
        head = new Node();
    }
    
    void insert(string word) {
        
        Node* curr = head;
        
        for(char ch: word) {
            
            if(curr->val[ch - 'a'] == NULL)
                curr->val[ch - 'a'] = new Node;
            
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
    
    bool check_word(Node* curr) {
        
        if(!curr)
            return false;
        
        if(curr->is_terminal)
            return true;
        
        for(int i = 0; i < 26; i++) {
            
            if(check_word(curr->val[i]))
                return true;
        }
        
        return false;
    }
    
    bool startsWith(string prefix) {
        
        Node* curr = head;
        
        for(char ch: prefix) {
            
            if(curr->val[ch - 'a'] == NULL)
                curr->val[ch - 'a'] = new Node;
            
            curr = curr->val[ch - 'a'];
        }
        
        return check_word(curr);
    
    }
};