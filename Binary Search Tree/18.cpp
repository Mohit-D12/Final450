// Conflicting Intervals
// https://leetcode.com/problems/my-calendar-i/

#include<bits/stdc++.h>
using namespace std;

class Node {
    
public:
    int start, end;
    Node* left, *right;
    
    Node(int l, int r) {
        
        start = l;
        end = r;
        left = NULL;
        right = NULL;
    }
};

class MyCalendar {
    
    Node* root;
    
public:
    MyCalendar() {
        
        root = NULL;
    }
    
    bool book(int start, int end) {
        
        if(!root) {
            
            root = new Node(start, end);
            return true;
        }
        
        Node* curr = root, *prev = root;
        while(curr) {
            
            prev = curr;
            if(curr->start >= end)
                curr = curr->left;
            else if(curr->end <= start)
                curr = curr->right;
            else
                return false;
        }
        
        if(prev->start >= end)
            prev->left = new Node(start, end);
        else if(prev->end <= start)
            prev->right = new Node(start, end);
        
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */