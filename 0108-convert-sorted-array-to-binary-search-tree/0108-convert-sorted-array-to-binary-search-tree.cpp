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
    TreeNode* maketree( vector<int>& nums,int start,int end, TreeNode* root)
    {
        if(start>end)return NULL;
        int mid = start + (end-start)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        if(root == NULL)
        {
            root = node;
        }
        root->left = maketree(nums, start , mid-1 , root->left);
        root->right = maketree(nums, mid+1 , end , root->right);
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        // int mid = nums.size()/2;
        // TreeNode* root = new TreeNode(mid);
        TreeNode* root = NULL;
        if(nums.size()==0)return root;
        return maketree( nums,0,nums.size()-1,root);
        
    }
};