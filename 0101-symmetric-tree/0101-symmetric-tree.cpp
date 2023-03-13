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
    bool symcheck(TreeNode* right, TreeNode* left)
    {
        if(right == NULL || left == NULL)
            return left == right;
        if(left->val != right->val)return false;
        
        return symcheck(right->right , left->left) && symcheck(right->left ,  left->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)return true;
        return symcheck(root->right, root->left);
    }
};