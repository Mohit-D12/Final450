// Count Inversions
// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

class Solution{
    void merge(long long* arr, long long i, long long mid, long long j, long long int& res)
    {
        long long a = i, b = mid+1;
        long long* temp = new long long[j - i + 1];
        long long count = 0;
        
        while(a <= mid && b <= j)
        {
            if(arr[a] <= arr[b])
            {
                temp[count++] = arr[a];
                a++;
            }
            else
            {
                temp[count++] = arr[b];
                b++;
                res += mid - a + 1;
            }
        }
        while(a <= mid)
        {
            temp[count++] = arr[a];
            a++;
        }
        while(b <= j)
        {
            temp[count++] = arr[b];
            b++;
        }
        
        for(int z = 0; z < count; z++)
            arr[z+i] = temp[z];
    }

    void merge_sort(long long* arr, long long i, long long j, long long int& res)
    {
        if(i >= j)
            return;
        
        int mid = i + (j - i)/2;
        merge_sort(arr, i, mid, res);
        merge_sort(arr, mid+1, j, res);
        merge(arr, i, mid, j, res);
    }

  public:
    long long int inversionCount(long long arr[], long long N)
    {
        long long int res = 0;
        merge_sort(arr, 0, N-1, res);
        return res;
    }

};