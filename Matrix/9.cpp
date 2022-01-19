// Kth smallest element in a row-wise and column-wise sorted 2D array | Set 1
// https://www.geeksforgeeks.org/kth-smallest-element-in-a-row-wise-and-column-wise-sorted-2d-array-set-1/

#include <bits/stdc++.h>
using namespace std;


class BinarySearchApproach
{

    int getElementsGreaterThanOrEqual(int num, int n, int mat[4][4]) {
        int ans = 0;

        for (int i = 0; i < n; i++) {
            
            if (mat[i][0] > num)
                return ans;

            if (mat[i][n - 1] <= num) 
            {
                ans += n;
                continue;
            }
            
            int greaterThan = 0;
            for (int jump = n / 2; jump >= 1; jump /= 2) 
            {
                while (greaterThan + jump < n && mat[i][greaterThan + jump] <= num)
                    greaterThan += jump;
                
            }

            ans += greaterThan + 1;
        }
        return ans;
    }

    int kthSmallest(int mat[4][4], int n, int k) 
    {
        int l = mat[0][0], r = mat[n - 1][n - 1];

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int greaterThanOrEqualMid = getElementsGreaterThanOrEqual(mid, n, mat);

            if (greaterThanOrEqualMid >= k)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};

class PriorityQueueApproach
{
    int kthSmallest(int mat[4][4], int n, int k)
    {
        auto cmp = [&](pair<int, int> a, pair<int, int> b){
            return mat[a.first][a.second] > mat[b.first][b.second];
        };
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        for(int i = 0; i < n; i++){
            pq.push({i,0});
        }
        
        for(int i = 1; i < k; i++){
            auto p = pq.top();
            pq.pop();
            
            if(p.second + 1 < n) pq.push({p.first,p.second + 1});
        }

        return mat[pq.top().first][pq.top().second];
    }

};

class MinHeapApproach
{
    struct HeapNode {
        int val; // value to be stored
        int r; // Row number of value in 2D array
        int c; // Column number of value in 2D array
    };

    // A utility function to minheapify the node harr[i] of a
    // heap stored in harr[]
    void minHeapify(HeapNode harr[], int i, int heap_size)
    {
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        if(l < heap_size&& r<heap_size && harr[l].val < harr[i].val && harr[r].val < harr[i].val){
                HeapNode temp=harr[r];
                harr[r]=harr[i];
                harr[i]=harr[l];
                harr[l]=temp;
                minHeapify(harr ,l,heap_size);
                minHeapify(harr ,r,heap_size);
            }
            if (l < heap_size && harr[l].val < harr[i].val){
                HeapNode temp=harr[i];            
                harr[i]=harr[l];
                harr[l]=temp;
                minHeapify(harr ,l,heap_size);
            }
    }

    // This function returns kth
    // smallest element in a 2D array
    // mat[][]
    int kthSmallest(int mat[4][4], int n, int k)
    {
        // k must be greater than 0 and smaller than n*n
        if (k < 0 && k >= n * n)
            return INT_MAX;

        // Create a min heap of elements from first row of 2D
        // array
        HeapNode harr[n];
        for (int i = 0; i < n; i++)
            harr[i] = { mat[0][i], 0, i };

        HeapNode hr;
        for (int i = 0; i < k; i++) {
            // Get current heap root
            hr = harr[0];

            // Get next value from column of root's value. If
            // the value stored at root was last value in its
            // column, then assign INFINITE as next value
            int nextval = (hr.r < (n - 1)) ? mat[hr.r + 1][hr.c]: INT_MAX;

            // Update heap root with next value
            harr[0] = { nextval, (hr.r) + 1, hr.c };

            // Heapify root
            minHeapify(harr, 0, n);
        }

        // Return the value at last extracted root
        return hr.val;
    }
};