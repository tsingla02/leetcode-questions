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
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder , int pre_start, int pre_end , int in_start , int in_end , map<int,int>& inorder_map)
    {
        if(pre_start > pre_end || in_start > in_end)return NULL;
        TreeNode* root = new TreeNode(preorder[pre_start]);
        
        
        int inroot = inorder_map[root->val];
        int numsleft = inroot - in_start;
        root->left = traversal(preorder , inorder, pre_start+1 , pre_start + numsleft, in_start , inroot-1 , inorder_map);
        root->right = traversal(preorder , inorder, pre_start + numsleft + 1 , pre_end , inroot+1 , in_end , inorder_map);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inorder_map;
        
        for(int i = 0 ; i < inorder.size() ; i++)
        {
            inorder_map[inorder[i]] = i ;
        }
        
        TreeNode* root = traversal(preorder , inorder, 0 , preorder.size()-1 , 0 , inorder.size()-1 , inorder_map);
        return root;
    }
};