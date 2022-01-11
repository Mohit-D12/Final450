// Value equal to index value
// https://practice.geeksforgeeks.org/problems/value-equal-to-index-value1330/1


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> valueEqualToIndex(int arr[], int n) {
    // code here
    vector<int> result;
    
    for(int i = 0; i < n; i++)
        if(arr[i] == i+1)
            result.push_back(i);
    
    return result;
}
};