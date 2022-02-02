// ANARC05B - The Double HeLiX
// https://www.spoj.com/problems/ANARC05B/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    int a[10000], b[10000];

    while(true)
    {
        cin >> n;
        
        if(n == 0)
            break;

        for(int i = 0; i < n; i++)
            cin >> a[i];
        cin >> m;
        for(int i = 0; i < m; i++)
            cin >> b[i];
        
        int ta = 0, tb = 0, sum = 0;
        int i = 0, j = 0;

        while(i < n && j < m)
        {
            if(a[i] == b[j])
            {
                sum += max(ta, tb) + a[i];
                ta = 0;
                tb = 0;
                i++;
                j++;
            }
            else if(a[i] < b[j])
            {
                ta += a[i];
                i++;
            }
            else
            {
                tb += b[j];
                j++;
            }
        }
        while(i < n)
        {
            ta += a[i];
            i++;
        }
        while(j < m)
        {
            tb += b[j];
            j++;
        }
        sum += max(ta, tb);

        cout << sum << endl;
        
        
        


    }

    return 0;
}