// First and last occurrences of x
// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1#


#include <bits/stdc++.h>
using namespace std;

#define log2 log(2)
#define pb push_back

// STL APPROACH
vector<int> stl(int arr[], int n , int x )
{
   vector<int> ans = {-1,-1};
   
   if(!binary_search(arr, arr+n, x)) return ans;
   int* low = lower_bound(arr, arr + n, x);
   auto up = upper_bound(arr, arr + n, x);
   
   ans[0] = low - arr;
   ans[1] = up - arr-1;
   
   return ans;
}

//binary search
int find_first_occurance(int* arr, int n, int x)
{
    int result = -1;
    int s = 0, e = n-1;
    int mid = s + (e - s)/2;

    while(s <= e)
    {
        if(arr[mid] == x)
        {
            result = mid;
            e = mid - 1;
        }
        else if(arr[mid] > x)
            e = mid - 1;
        else    
            s = mid + 1;
        
        mid = s + (e - s)/2;
    }

    return result;
}

int find_last_occurance(int* arr, int n, int x)
{
    int result = -1;
    int s = 0, e = n-1;
    int mid = s + (e - s)/2;

    while(s <= e)
    {
        if(arr[mid] == x)
        {
            result = mid;
            s = mid + 1;
        }
        else if(arr[mid] < x)
            s = mid + 1;
        else
            e = mid - 1;
        
        mid = s + (e - s)/2;
    }
    
    return result;
}

vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> result;     // [first_occurance, last_occurance]

    result.pb(find_first_occurance(arr, n, x));

    if (result[0] == -1)
        result.pb(-1);
        return result;
    
    result.pb(find_last_occurance(arr+result[0], n-result[0], x));
    
    return result;
    

}

int main() 
{
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

