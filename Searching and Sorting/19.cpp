// Bishu and Soldiers
// https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/

#include<bits/stdc++.h>
using namespace std;

void init(int* arr, int n, int*cumm)
{
    int sum = 0;
    sort(arr, arr+n);

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        cumm[i] = sum;
    }
}
void input(int* arr, int n)
{
    for(int i = 0; i < n; i++)
        cin >> arr[i];
}

int main()
{
    int arr[10000], cumm[10000];
    int sum = 0;
    int n, q, p, z;

    cin >> n;
    input(arr, n);
    init(arr, n, cumm);
    cin >> q;

    for(int i = 0; i < q; i++)
    {
        cin >> p;
        z = upper_bound(arr, arr+n, p) - arr;

        cout << z << ' ' << cumm[z-1] << endl;
    }

    return 0;
}