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
    
    bool ans(TreeNode* root)
    {
        if(root->val == 2)
        {
            if(ans(root->left) || ans(root->right))
                return true;
        }
        if(root->val == 3)
        {
            if(ans(root->left) && ans(root->right))
                return true;
        }
        if(root->val == 1)
        {
            return true;
        }
        if(root->val == 0)
            return false;
        return false;
    }
    bool evaluateTree(TreeNode* root) {
        return ans(root);
    }
};