// Write a program to reverse an array or string
// geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/


#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int start, int end)
{

	if (start >= end)
	return;
	
	int temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;
	
	reverseArray(arr, start + 1, end - 1);

}	

