// Print Anagrams Together 
// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1

#include<bits/stdc++.h>
using namespace std;

class Node {
    
public:
    Node* val[26];
    bool is_terminal;
    int group_number;
    
    Node() {
        
        for(int i = 0; i < 26; i++)
            this->val[i] = NULL;
            
        this->is_terminal = false;
        this->group_number = -1;
    }
};

class Trie {
  
  public:  
    Node* head;
    int group_number;
    
    Trie() {
        
        head = new Node();
        group_number = 0;
    }
    
    int insert(string word) {
        
        Node* curr = head;
        
        for(char ch: word) {
            
            if(curr->val[ch - 'a'] == NULL)
                curr->val[ch - 'a'] = new Node();
            
            curr = curr->val[ch - 'a'];
        }
        
        if(!curr->is_terminal) {
            
            curr->is_terminal = true;
            curr->group_number = group_number++;
        }
        
        return curr->group_number;
    }
    
};

class Solution{
  public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        
        //code here
        vector<vector<string>> result;
        Trie* t = new Trie();
        
        for(string str: string_list) {
            
            string s = str;
            sort(s.begin(), s.end());
            
            int grp = t->insert(s);
            // cout << s << ' ' << grp << endl;
            
            while(grp >= result.size())
                result.push_back({});
                
            result[grp].push_back(str);
        }
        
        return result;
        
    }
};