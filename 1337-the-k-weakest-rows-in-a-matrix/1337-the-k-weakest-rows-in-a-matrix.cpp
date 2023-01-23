class Solution
{
    public:
        vector<int> kWeakestRows(vector<vector < int>> &mat, int k)
        {
            priority_queue<pair<int, int>> q;
            for (int i = 0; i < mat.size(); i++)
            {
                int count = 0;
                while (mat[i][count] == 1)
                {
                    count++;
                    if (count == mat[i].size()) break;
                }
                if (q.size() <= k)
                {
                    q.push(make_pair(count, i));
                }
                else
                {
                    q.push(make_pair(count, i));
                    q.pop();
                }
            }
            if (q.size() > k)
            {

                q.pop();
            }

            vector<int> ans;
            stack<int> ansl;
            while (!q.empty())
            {
                ansl.push(q.top().second);
                q.pop();
            }
            while (!ansl.empty())
            {
                ans.push_back(ansl.top());
                ansl.pop();
            }
            return ans;
        }
};