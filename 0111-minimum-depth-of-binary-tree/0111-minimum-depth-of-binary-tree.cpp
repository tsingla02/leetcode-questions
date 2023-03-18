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
    int ans=INT_MAX;
    bool isleaf(TreeNode* root)
    {
        if(!root->right && !root->left)return true;
        return false;
    }
    void traversal(TreeNode* root, int minh)
    {
        if(root == NULL)return ;
        minh =  minh+1;
        // cout<<root->val<<" "<<minh<<endl;
        if(isleaf(root)){ans = min(ans,minh);}
        
        traversal(root->left,minh);
        traversal(root->right,minh);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int minh = 0;
        traversal(root,minh);
        return ans;
    }
};