// EKO Wood cutting problem
// https://www.spoj.com/problems/EKO/


#include <bits/stdc++.h>
using namespace std;

// one better approach was to create a cumm sum array to get res in is_possible() in O(1) but it takes way more memeory.

bool is_possible(int* arr, int n, int height, int m)
{
    int index = lower_bound(arr, arr+n, height) - arr;
    long long int res = 0;
    
    for(int i = index; i < n; i++)
        res += arr[i] - height;

    return res >= m;
    
}

int main()
{
    int m, n, t;
    int* a = new int[1000000];
    
        cin >> n >> m;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);

        int s = 0, e = a[n-1];
        int mid = s + (e - s)/2;
        int res = -1;

        while(s <= e)
        {
            if(is_possible(a, n, mid, m))
            {
                res = mid;
                s = mid + 1;
            }
            else
                e = mid - 1;
            
            mid = s + (e - s)/2;
        }

        cout << res << endl;

    return 0;
}