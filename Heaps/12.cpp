// Find Median from Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/

#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
    
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    
    int signum() {
        
        if(left.size() == right.size())
            return 0;
        
        return (left.size() > right.size())? -1: 1;
    }
    
public:
    MedianFinder() {
    
        left = {};
        right = {};
    }
    
    void addNum(int num) {
        
        int bal = signum();
        double median = findMedian();
        
        if(num > median) {
            
            // num to be added in right
            if(bal < 1)
                right.push(num);
            
            else {
                
                left.push(right.top());
                right.pop();
                right.push(num);
            }
                
        }
        else {
            
            // num to be added in left
            if(bal > -1)
                left.push(num);
            
            else {
                
                right.push(left.top());
                left.pop();
                left.push(num);
            }
        }
        
    }
    
    double findMedian() {
        
        int bal = signum();
        
        if(bal == 0) {
            
            if(!left.size())
                return 0;
            
            return (left.top() + right.top()) / 2.0;
        }
            
        
        if(bal == 1)
            return right.top();
        
        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */