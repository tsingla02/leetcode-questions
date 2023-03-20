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
    int height(TreeNode* root)
    {
        if(root == NULL)return 0;
        return 1+max(height(root->left), height(root->right));
    }
    int flag = 0;
    void traversal(TreeNode* root)
    {
        if(root == NULL)return;
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh-rh) > 1)flag = 1;
        traversal(root->left);
        traversal(root->right);
    }
    bool isBalanced(TreeNode* root) {
        traversal(root);
        if(flag == 1)return false;
        return true;
    }
};