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
    int sum(TreeNode* root)
    {
        if(root == NULL)return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    void frequency(TreeNode* root , unordered_map<int,int>& pq)
    {
        if(root == NULL)return;
        pq[sum(root)]++;
        frequency(root->left,pq);
        frequency(root->right,pq);

    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> pq;
        frequency(root, pq);
        vector<int> ans;
        int m = INT_MIN;
        for(auto x: pq)
        {
            m = max(m,x.second);
        }
        for(auto x:pq)
        {
            if(x.second == m)
                ans.push_back(x.first);
        }
        return ans;
    }
};