// AGGRCOW - Aggressive cows
// https://www.spoj.com/problems/AGGRCOW/

#include<bits/stdc++.h>
using namespace std;

bool is_possible(int* arr, int n, int c, int key)
{
    int count = 1;
    int prev = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(count == c)
            return true;
        
        if (arr[i] - prev >= key)
        {
            count++;
            prev = arr[i];
        }
    }

    if (count == c)
        return true;
    
    return false;
}

int main()
{
    int t, n, c;
    int a[100000];

    cin >> t;
    while(t--)
    {
        cin >> n >> c;
        
        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a+n);

        int s = 0, e = a[n-1] - a[0] + 1;
        int mid = s + (e - s)/2;
        int ans = -1;
        
        while(s <= e)
        {
            if(is_possible(a, n, c, mid))
            {
                ans = mid;
                s = mid + 1;
            }
            else
                e = mid - 1;
            
            mid = s + (e - s)/2;
        }

        cout << ans << endl;
    }

    return 0;
}