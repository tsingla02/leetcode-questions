class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i = 0; i<words.size() ; i++)
        {
            string s;
            s = words[i];
            reverse(s.begin(),s.end());
            if(s == words[i])
            {
                return words[i];
            }
        }
        string si = "";
        return si;
    }
};