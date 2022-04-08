// Shortest Unique prefix for every word
// https://practice.geeksforgeeks.org/problems/shortest-unique-prefix-for-every-word/1/#

#include<bits/stdc++.h>
using namespace std;

class Node {
    
public:
    Node* val[26];
    Node* parent;
    bool is_terminal;
    
    Node() {
        
        for(int i = 0; i < 26; i++)
            this->val[i] = NULL;
            
        this->is_terminal = false;
    }
    
    Node(Node* parent) {
        
        Node();
        this->parent = parent;
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
                curr->val[ch - 'a'] = new Node(curr);
            
            curr = curr->val[ch - 'a'];
        }
        
        curr->is_terminal = true;
    }
    
    Node* search(string word) {
        
        Node* curr = head;
        
        for(char ch: word) {
            
            if(curr->val[ch - 'a'] == NULL)
                curr->val[ch - 'a'] = new Node(curr);
            
            curr = curr->val[ch - 'a'];
        }
        
        if(curr->is_terminal)
            return curr;
            
        return NULL;
    }
    
    string find_prefix(string word) {
        
        Node* curr = search(word);
        
        while(word.length() > 1) {
            
            if(!curr->parent || curr->parent->count_children() > 1)
                break;
            
            word.pop_back();
            curr = curr->parent;
        }
        
        return word;
    }
};

class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        Trie* t = new Trie();
        vector<string> result;
        
        for(int i = 0; i < n; i++)
            t->insert(arr[i]);
        
        
        for(int i = 0; i < n; i++)
            result.push_back(t->find_prefix(arr[i]));
            
        delete t;
        return result;
    }
    
};