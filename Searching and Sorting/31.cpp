// PRATA - Roti Prata
// https://www.spoj.com/problems/PRATA/

#include <bits/stdc++.h>
using namespace std;

bool check(int* r, int p, int time)
{
    int prata = 0;
    for(int i = 1; i < 9; i++)
    {
        if(r[i] == 0)
            continue;
        int t = i;
        int jump = 2*i;
        while(t <= time)
        {
            prata += r[i];
            t += jump;
            jump += i;

            if(prata >= p)
                return true;
        }
    }

    return (prata >= p);
}

int main()
{
    int t, p, l, temp;

    cin >> t;
    while(t--)
    {
        int r[9] = {0};
        int s = 0, e = 4004000;
        int res = -1;
        int mid = s + (e - s)/2;

        cin >> p >> l;
        for(int i = 0; i < l; i++)
        {
            cin >> temp;
            r[temp]++;
        }


        while(s <= e)
        {
            if(check(r, p, mid))
            {
                res = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
            
            mid = s + (e - s)/2;
        }

        cout << res << endl;
    }
    return 0;
}