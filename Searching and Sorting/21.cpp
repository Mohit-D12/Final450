// Kth smallest number again
// https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/kth-smallest-number-again-2/

#include<bits/stdc++.h>
using namespace std;

#define last(a) a[a.size() - 1]
#define vp vector<pll>
#define vl vector<ll>
#define pll pair<ll, ll>
#define ll long long int

bool cmp(pll& a, pll& b){
    return (a.first < b.first);
}

void input_ranges(vp& a, int n){
    for(int i = 0; i < n; i++)
    {
        pll temp;
        cin >> temp.first >> temp.second;
        a.push_back(temp);
    }
}

void merge_ranges(vp& a, int n, vp& r){   
    sort(a.begin(), a.end(), cmp);
    r.push_back(a[0]);

    for(int i = 0; i < n; i++)
    {
        if (last(r).second >= a[i].first)
            last(r).second = max(last(r).second, a[i].second);
        else
            r.push_back(a[i]);
    }
}

void fill_cumm_sum(vl& cumm, vp& r){
    ll sum = 0;

    for(int i = 0; i < r.size(); i++)
    {
        sum += r[i].second - r[i].first + 1;
        cumm.push_back(sum);
    }
}

ll get_kth_element(ll k, vl& cumm, vp& r){

    if(k > last(cumm) || k < 1)
        return -1;

    int x = lower_bound(cumm.begin(), cumm.end(), k) - cumm.begin();
    if (x > 0)
        k -= cumm[x - 1];
    
    return r[x].first + k - 1;
}

void reset(vp& a, vp& r, vl& cumm)
{
    a.clear();
    r.clear();
    cumm.clear();
}

int main()
{
    int t, n, q;
    ll k;

    vp a, r;
    vl cumm;

    cin >> t;
    while(t--)
    {
        cin >> n >> q;

        reset(a, r, cumm);   
        input_ranges(a, n);
        merge_ranges(a, n, r);
        fill_cumm_sum(cumm, r);

        for(int i = 0; i < q; i++)
        {
            cin >> k;
            cout << get_kth_element(k, cumm, r) << endl;
        }
    }
    
    return 0;
}
