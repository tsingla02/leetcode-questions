class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        // int flag = 0;
        for (int i = 0 ; i< nums.size() ; i++)
        {
            mp[nums[i]]++;
        }
        for(auto x:mp)
        {
            if(x.second >= 2)
            {
                // flag = 1;
                return true;
                break;
            }
            
        }
        return false;
    }
};