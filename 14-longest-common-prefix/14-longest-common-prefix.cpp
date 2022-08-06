class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i = 0; i< strs.size() ; i++)
        {
            for(int j = 0 ; j< ans.size() ; j++)
            {   
                if(ans[j] == strs[i][j])
                {
                    continue;
                }
                else
                {
                    ans.erase(j);
                }
            }
        }
        return ans;
    }
};