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
    void traversal(TreeNode* p, TreeNode* q , int &flag)
    {
        if(p == NULL && q == NULL)
            return;
        else if(p != NULL && q == NULL)
            {flag = 1;
            }
        else if(p == NULL && q != NULL)
            {flag = 1;
            }
        
        
        if(flag != 1)
        {
            if(p->val != q->val)
            flag = 1;
            traversal(p->left,q->left,flag);
            traversal(p->right,q->right,flag);
        }
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        int flag = 0;
        traversal(p,q,flag);
        if(flag == 1)
            return false;
        else 
            return true;
    }
};