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
    void traversal(TreeNode* root, int prev_max , int &count)
    {
        if(root == NULL)return;
        if(root->val >= prev_max)count++;
        prev_max = max(prev_max, root->val);
        traversal(root->left, prev_max, count);
        traversal(root->right, prev_max, count);
        
    }
    int goodNodes(TreeNode* root) {
        int prev_max = INT_MIN;
        int count = 0;
        traversal(root, prev_max , count);
        return count;
    }
};