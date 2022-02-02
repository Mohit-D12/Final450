// SUBSUMS - Subset Sums
// https://www.spoj.com/problems/SUBSUMS/

#include<bits/stdc++.h>
using namespace std;

void subset_sum(int* arr, int i, int j, long long int& sum, vector<long long int>& res)
{
    if(i == j)
    {
        res.push_back(sum);
        return;
    }
    
    subset_sum(arr, i+1, j, sum, res);
    sum += arr[i];
    subset_sum(arr, i+1, j, sum, res);
    sum -= arr[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    int arr[34];
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    vector<long long int> x, y;
    long long int sum = 0;
    subset_sum(arr, 0, n/2, sum, x);
    subset_sum(arr, n/2, n, sum, y);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    // for(auto i:x)
    //     cout << i << ' ';
    // cout << endl;
    // for(auto i:y)
    //     cout << i << ' ';
    // cout << endl;

    long long int res = 0;
    for(auto i:x)
    {
        res += (upper_bound(y.begin(), y.end(), b - i) - y.begin()) - (lower_bound(y.begin(), y.end(), a - i) - y.begin());
    }

    cout << res << endl;
    return 0;
}
