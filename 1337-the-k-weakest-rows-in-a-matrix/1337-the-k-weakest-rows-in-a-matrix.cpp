class Solution
{
    public:
        vector<int> kWeakestRows(vector<vector < int>> &mat, int k)
        {
            priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> q;
            for (int i = 0; i < mat.size(); i++)
            {
                int count = 0;
                while (mat[i][count] == 1 )
                {
                    count++;
                    if(count == mat[i].size())break;
                }

                q.push(make_pair(count, i));
            }
            vector<int> ans;
            while (!q.empty() && k != 0)
            {
                pair<int, int> top = q.top();
                ans.push_back(top.second);
                q.pop();
                k--;
            }
            return ans;
        }
};