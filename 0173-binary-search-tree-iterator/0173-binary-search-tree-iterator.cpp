/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class BSTIterator
{
    stack<TreeNode*> st;
    public:
    BSTIterator(TreeNode *root)
    {
        pushr(root);
    }

    int next()
    {
        if (!st.empty())
        {
            TreeNode *t = st.top();
            st.pop();
            pushr(t->right);
            return t->val;
        }
        return -1;
    }

    bool hasNext()
    {
        if (!st.empty()) return true;
        return false;
    }
    void pushr(TreeNode* root)
    {
        if (root)
        {
            st.push(root);
            pushr(root->left);
        }
    }
};

/**
 *Your BSTIterator object will be instantiated and called as such:
 *BSTIterator* obj = new BSTIterator(root);
 *int param_1 = obj->next();
 *bool param_2 = obj->hasNext();
 */