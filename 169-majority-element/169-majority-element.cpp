class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0; i<nums.size() ; i++)
        {
            mp[nums[i]]++;
        }
        int t = 0;
        int n;
        for(auto x: mp)
        {
            if(x.second > t)
            {
                t = x.second;
                n = x.first;
            }
        }
        return n;
    }
};