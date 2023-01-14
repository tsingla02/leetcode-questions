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
    int count = 0;
    int sum(TreeNode* root,int &s)
    {
        if(root == NULL)return 0;
        s += root->val;
        sum(root->left,s);
        sum(root->right,s);
        
        return s;
    }
    void tree(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        int suml = 0;
        int sumr = 0;
        suml = sum(root->left,suml);
        sumr = sum(root->right,sumr);
        // cout<<suml<<" "<<sumr<<endl;
        // root->val = abs(suml-sumr);
        tree(root->left);
        tree(root->right);
        count = count + abs(suml-sumr);
    }
    int findTilt(TreeNode* root) {
        tree(root);
        int t=0;
        return count;
    }
};