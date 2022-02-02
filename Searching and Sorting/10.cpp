// Find Pair Given Difference
// https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1

#include<bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n){
    //code
    sort(arr, arr+size);
    int i = 0; 
    int j = 1; 

    // Search for a pair 
    while (i < size && j < size) 
    { 
        if (i != j && (arr[j] - arr[i] == n || arr[i] - arr[j] == n) )
            return true; 
            
        else if (arr[j]-arr[i] < n) 
            j++; 
        else
            i++; 
    } 

    return false; 
    
}