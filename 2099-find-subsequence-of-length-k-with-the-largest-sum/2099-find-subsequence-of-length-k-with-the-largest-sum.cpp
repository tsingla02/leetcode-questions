class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            pq.push(make_pair(nums[i],i));
        }
        map<int,int> mp;
        for(int i = 0 ; i < k ; i++)
        {
            mp[pq.top().second] = pq.top().first;
            pq.pop();
        }
        vector<int>ans;
        for(auto i : mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};