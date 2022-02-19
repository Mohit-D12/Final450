// 103. Binary Tree Zigzag Level Order Traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return {};

        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        
        bool flag = false;

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
            if(flag)
                reverse(temp.begin(), temp.end());
            flag = !flag;
            ans.push_back(temp);
        }
        
        return ans;
    }
};