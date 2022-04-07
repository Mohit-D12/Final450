// Find largest subtree sum in a tree
// https://www.geeksforgeeks.org/find-largest-subtree-sum-tree/

#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    Node *left, *right;
};
 
int findLargestSubtreeSumUtil(Node* root, int& ans)
{
    if (root == NULL)    
        return 0;
     
    int currSum = root->key +
      findLargestSubtreeSumUtil(root->left, ans)
      + findLargestSubtreeSumUtil(root->right, ans);
 
    ans = max(ans, currSum);

    return currSum;
}
 
int findLargestSubtreeSum(Node* root)
{
    if (root == NULL)    
        return 0;
    int ans = INT_MIN;
 
    findLargestSubtreeSumUtil(root, ans);
 
    return ans;
}