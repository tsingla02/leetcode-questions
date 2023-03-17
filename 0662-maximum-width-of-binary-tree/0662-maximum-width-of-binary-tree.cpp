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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)return 0;
        queue<pair<int,TreeNode*>> q;
        int width = 0;
        int index = 0;
        q.push({0,root});
        while(!q.empty())
        {
            int size = q.size();
            int first = q.front().first;
            int last = q.back().first;
            width= max(last-first+1, width);
            for(int i = 0 ; i< size ; i++)
            {
                TreeNode* t = q.front().second;
                index = q.front().first - first;
                TreeNode* node = q.front().second;
                q.pop();
                if(t->left)q.push({(long long)2*index, t->left});
                if(t->right)q.push({ (long long)2*index+1, t->right});
            }
        }
        return width;
    }
};