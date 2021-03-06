// 102. Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root==NULL)
            return {};

        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);

        while(q.size()) {

            vector<int> temp;

            int count=q.size();
            while(count--) {

                TreeNode* front=q.front();
                q.pop();

                temp.push_back(front->val);

                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }

            ans.push_back(temp);
        }
        
        return ans;
    }
};