class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i = 0 ; i < s.size() ; i++)
        {
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto x:mp)
        {
            pq.push(make_pair(x.second,x.first));
        }
        string ans;
        while(!pq.empty())
        {
            int t = pq.top().first;
            while(t--)
            {
                ans.push_back(pq.top().second);
            }
            pq.pop();
        }
        return ans;
    }
};