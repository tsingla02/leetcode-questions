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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root== NULL)
        {
            TreeNode* nroot = new TreeNode(val);
            root = nroot;
            return nroot;
        }
        TreeNode* node = root;
        TreeNode* prev_node = root;
        while(node)
        {
            prev_node = node;
            if(node->val > val)node = node->left;
            else node = node->right;
        }
        TreeNode* nroot = new TreeNode(val);
        if(prev_node->val > val) prev_node->left = nroot;
        else prev_node->right = nroot;
        return root;
    }
};