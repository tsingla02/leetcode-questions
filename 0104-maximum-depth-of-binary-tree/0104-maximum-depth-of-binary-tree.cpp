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
    int height(TreeNode* root, int &co)
    {
        if(root == NULL)
        {
            return 0;
        }
        co = max(height(root->left,co),height(root->right,co));
        return co+1;
    }
    int maxDepth(TreeNode* root) {
        int co = 0;
        return height(root, co);
        
    }
};