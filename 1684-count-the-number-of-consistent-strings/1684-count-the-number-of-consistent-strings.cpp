class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> mp;
        for(int i = 0 ; i< allowed.size() ; i++)
        {
            mp[allowed[i]]++;
        }
        int count= 0 ;
        for(int i = 0 ; i < words.size() ; i++)
        {
            for(int j = 0 ; j < words[i].size() ; j++)
            {
                if(!mp.count(words[i][j]))
                {
                    count++;
                    break;
                }
            }
        }
        return words.size()-count;
    }
};