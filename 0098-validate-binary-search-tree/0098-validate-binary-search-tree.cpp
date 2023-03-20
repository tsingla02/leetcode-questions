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
    int flag = 0;
    void validate(TreeNode* root, long long int lower ,long long int higher)
    {
        if(root == NULL)return;
        if(root->val <= lower || root->val >= higher)flag = 1;
        validate(root->left, lower, root->val);
        validate(root->right, root->val, higher);
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL)return true;
//         if(root->val == INT_MIN)
//         {
            
//             if(root->left != NULL)return false;
//             validate(root->right, INT_MIN, INT_MAX);
//             if(flag == 1){return false;}
//             else return true;
//         }
//         else if(root->val == INT_MAX)
//         {
//             if(root->right != NULL)return false;
//             validate(root->right, INT_MIN, INT_MAX);
//             // cout<<"is this here";
//             if(flag == 1){return false;}
//             else return true;
//         }
        // int t = INT_MIN;
        long long int lower = -2147483648 -1;
        // t = INT_MAX;
        long long int higher = 2147483648;
        validate(root, lower, higher);
        if(flag == 1){return false;}
        return true;
    }
};