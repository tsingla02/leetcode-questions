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
    TreeNode* traversal(vector<int>& inorder , int in_start, int in_end ,vector<int>& postorder, int post_start , int post_end, map<int,int>& inorder_map)
    {
        if(in_start>in_end || post_start > post_end)return NULL;
        
        TreeNode* root = new TreeNode(postorder[post_end]);
        
        int inroot =   inorder_map[root->val];
        int numsleft = inroot- in_start;
        
        root->left = traversal(inorder, in_start , inroot-1 , postorder , post_start , post_start-1+numsleft , inorder_map);
        root->right = traversal(inorder, inroot+1 , in_end , postorder , post_start+numsleft , post_end-1 , inorder_map);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inorder_map;
        for(int i = 0 ; i< inorder.size() ; i++)
        {
            inorder_map[inorder[i]] = i;
        }
        
        TreeNode* root = traversal(inorder, 0 , inorder.size()-1 , postorder , 0 , postorder.size()-1 , inorder_map);
        return root;
    }
};