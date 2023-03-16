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
    void traversal(TreeNode* root, int level, int vertical_order, priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>& pq)
    {
        if (root == NULL )return;
        pq.push(make_pair(vertical_order,make_pair(level,root->val)));
        traversal(root->left,level+1, vertical_order-1, pq);
        traversal(root->right,level+1, vertical_order+1, pq);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        int level = 0;
        int vertical_order = 0;
        traversal(root, level, vertical_order, pq);
        vector<vector<int>> ans;
        int f = pq.top().first;
        while(!pq.empty())
        {
            vector<int>entry;
            while(f == pq.top().first && !pq.empty())
            {
                entry.push_back(pq.top().second.second);
                pq.pop();
            }
            ans.push_back(entry);
            f = pq.top().first;
        }
        return ans;
    }
};