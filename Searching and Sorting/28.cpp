// Find the missing number in Arithmetic Progression
// https://www.geeksforgeeks.org/find-missing-number-arithmetic-progression/

#include<iostream>
using namespace std;

int findMissingUtil(int arr[], int low, int high, int diff)
{
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if ( (arr[mid] - arr[0]) / diff == mid)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return arr[high] + diff;
}

int findMissing(int arr[], int n)
{
	int diff = (arr[n - 1] - arr[0]) / n;
	return findMissingUtil(arr, 0, n - 1, diff);
}

