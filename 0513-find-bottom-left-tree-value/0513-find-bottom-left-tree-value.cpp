/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);
        TreeNode* ans; 
        while(!q.empty())
        {
            ans = q.front();
            q.pop();
            if(ans->right) q.push(ans->right);
            if(ans->left)q.push(ans->left);
        }
        return ans->val;
    }
};