/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<vector < int>> levelOrderBottom(TreeNode *root)
        {
            vector<vector<int>> final_ans;
            vector<vector<int>> ans;
            if(root == NULL)return final_ans;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())
            {
                vector<int> level;
                int s = q.size();
                for (int i = 0; i < s; i++)
                {
                    TreeNode* temp = q.front();
                    q.pop();
                    if (temp->left)
                    {
                        q.push(temp->left);
                    }
                    if (temp->right)
                    {
                        q.push(temp->right);
                    }
                    level.push_back(temp->val);
                }
                ans.push_back(level);
                
                
            }
            int si = ans.size();
                for(int i = si-1; i>=0 ; i--)
                {
                    final_ans.push_back(ans[i]);
                }
            return final_ans;
        }
};