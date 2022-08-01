class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<int, int> mp;
        int count =0;
        for(int i =0 ;i<stones.size() ; i++)
        {
            mp[stones[i]]++;
        }

        for(auto x : mp)
        {
            for(int i =0 ;i<jewels.size() ; i++)
            {
                if(x.first == jewels[i])
                    count += x.second;
            }
        }
        return count;
    }
};