class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(p.size()>s.size())return ans;
        unordered_map<char,int>mp2;
        unordered_map<char,int>mp1;
        for (int i = 0 ; i< p.size(); i++)
        {
            mp1[s[i]]++;
            mp2[p[i]]++;
        }
        if(mp1 == mp2)ans.push_back(0);
        
        for(int i = p.size() ; i<s.size() ; i++)
        {
            mp1[s[i]]++;
            mp1[s[i-p.size()]]--;
            if(mp1[s[i-p.size()]] == 0)mp1.erase(s[i-p.size()]);
            if(mp1 == mp2)ans.push_back(i-p.size()+1);
        }
        return ans;
    }
};