/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void traversal(TreeNode* root, vector<TreeNode*> &arr)
    {
        if(root == NULL)
        {
            // arr.push_back(NULL);
            return;
        }
        arr.push_back(root);
        traversal(root->left,arr);
        traversal(root->right,arr);
        
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        vector<TreeNode*> nodes_vec;
        vector<TreeNode*> nodes_val;

        traversal(original,nodes_vec);
        traversal(cloned,nodes_val);
        
        int t;
        for(int i = 0 ; i< nodes_vec.size() ; i++)
        {
            if(target == nodes_vec[i])
            {
                t = i;
                break;
            }
        }
        return nodes_val[t];
    }
};