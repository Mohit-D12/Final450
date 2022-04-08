// Phone directory 
// https://practice.geeksforgeeks.org/problems/phone-directory4628/1

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
    
    void check_word(Node* curr, string& s, vector<string>& result) {
        
        if(!curr)
            return;
        
        if(curr->is_terminal)
            result.push_back(s);
        
        for(int i = 0; i < 26; i++) {
            
            if(curr->val[i] != NULL) {
                
                s.push_back(i + 'a');
                check_word(curr->val[i], s, result);
                s.pop_back();
            }
        }
    }
    
    vector<string> startsWith(string prefix) {
        
        Node* curr = head;
        
        string str = prefix;
        vector<string> result;
        
        for(char ch: prefix) {
            
            if(curr->val[ch - 'a'] == NULL)
                curr->val[ch - 'a'] = new Node;
            
            curr = curr->val[ch - 'a'];
        }
        
        check_word(curr, str, result);
        
        if(result.size() == 0)
            result.push_back("0");
        return result;
        
    
    }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>> result;
        Trie t;
        
        for(int i = 0; i < n; i++) {
            
            t.insert(contact[i]);
        }
        
        string prefix = "";
        for(char ch: s) {
            
            prefix.push_back(ch);
            result.push_back(t.startsWith(prefix));
        }
        
        return result;
    }
};
