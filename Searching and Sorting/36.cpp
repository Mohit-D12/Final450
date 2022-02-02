#include<bits/stdc++.h>
using namespace std;

class Quicksort_with_duplicates
{
    int partition(int* a, int i, int j)
    {
        //swap last element with a random element
        int r = rand() % (j - i + 1) + i;
        swap(a[r], a[j]);

        //partition : [< = ! >] : [< = >]
        int x = i, y = j-1;    
        int e = a[j];

        int z = x;
        while(z <= y)
        {
            if(a[z] < e)
            {
                swap(a[z], a[x]);
                x++;
                z++;
            }
            else if(a[z] > e)
            {
                swap(a[z], a[y]);
                y--;
            }
            else
                z++;
        }

        swap(a[z], a[j]);
        return z;
    }

  public:
    void quick_sort(int* a, int i, int j)
    {
        if (i >= j)
            return;

        int right_pivot = partition(a, i, j);
        if (right_pivot < j - 1)
            quick_sort(a, right_pivot + 1, j);

        int left_pivot = lower_bound(a + i, a + right_pivot + 1, a[right_pivot]) - a;
        if (left_pivot > i)
            quick_sort(a, i, left_pivot-1);
    }
};