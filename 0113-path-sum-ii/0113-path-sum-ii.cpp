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
    bool isleaf(TreeNode* root)
    {
        if(!root->left && !root->right)return true;
        return false;
    }
    void traversal(TreeNode* root, int sum, int targetSum, vector<vector<int>>& ans, vector<int> ans1)
    {
        if(root == NULL)return;
        sum = sum + root->val;
        ans1.push_back(root->val);
        if(sum == targetSum && isleaf(root))ans.push_back(ans1);
        traversal(root->left, sum, targetSum, ans, ans1 );
        traversal(root->right, sum, targetSum, ans, ans1);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> ans1;
        int sum = 0;
        traversal(root, sum, targetSum, ans, ans1);
        return ans;
    }
};