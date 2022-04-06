#include<bits/stdc++.h>
using namespace std;
 
// SOLUTION 1: USING SET: O(NlogN) O(N) 
void solve_using_stl_set(vector<int>& arr) {

    set<int> s;
    vector<int> ans(arr.size());

    for(int i = arr.size() - 1; i >= 0; i--) { 
        
        s.insert(arr[i]);
        auto it = s.upper_bound(arr[i]);

        if(it == s.end()) 
            arr[i] = -1; 
        else 
            arr[i] = *it;
    }
}

// SOLUTION 2: USING Stack: O(NlogN) O(N) 

vector<int> nextGreaterIndex(vector<pair<int, int> >& temp) {

    int n = temp.size();
    vector<int> res(n, -1);
    stack<int> stack;

    for (int i = 0; i < n; i++) {

        if (stack.empty() || temp[i].second < stack.top())
            stack.push(temp[i].second); 

        else {

            while (!stack.empty() && temp[i].second > stack.top()) {

                res[stack.top()] = temp[i].second;
                stack.pop();
            }

            stack.push(temp[i].second);
        }
    }
    return res;
}

vector<int> replaceByLeastGreaterUsingStack(int arr[], int n) {

    vector<pair<int, int> > temp;

    for (int i = 0; i < n; i++)
        temp.push_back({ arr[i], i });
    
    sort(temp.begin(), temp.end());
    vector<int> indexes = nextGreaterIndex(temp);
    vector<int> res(n, -1);

    for (int i = 0; i < n; i++) {

        if (indexes[temp[i].second] != -1)
            res[temp[i].second] = arr[indexes[temp[i].second]];
    }
    return res;
}