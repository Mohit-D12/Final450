// Heapsort
// https://practice.geeksforgeeks.org/problems/heap-sort/1/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    
  public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i) {
        
        int left, right, mx;
        
        while(i < n) {
          
            left = 2 * i + 1;
            right = left + 1;
            
            mx = (right < n && arr[left] < arr[right])? right : left;
            
            if(mx < n && arr[mx] > arr[i]) {
                
                swap(arr[mx], arr[i]);
                i = mx;
            }
            else
                return;
        }
    }

    //Function to build a Heap from array.
    void buildHeap(int arr[], int n) { 
        
        for (int i = n / 2 - 1; i >= 0; i--) {
            
            heapify(arr, n, i);
        }
    }

    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n) {
        
        buildHeap(arr, n);
        
        for (int i = n - 1; i > 0; i--) {
            
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};