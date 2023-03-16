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
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL)return true;
        queue<TreeNode* > q;
        q.push(root);
        int level = -1;
        int check;
        int prev_check;
        while(!q.empty())
        {
            level++;
            if(level%2 == 0)check = INT_MIN;
            else check = INT_MAX;
            int size =q.size();
            for(int i = 0 ; i< size; i++)
            {
                TreeNode* node  = q.front();
                q.pop();
                if(level%2 ==0)
                {
                    prev_check = check;
                    check = max(check, node->val);
                    // cout<<level<<" "<<node->val<<" "<<endl;
                    if(check == prev_check)return false;
                    if(node->val %2 == 0)return false;
                }
                else
                {
                    prev_check = check;
                    check = min(check, node->val);
                    if(check == prev_check)return false;
                    if(node->val %2 != 0)return false;
                }
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return true;
    }
};