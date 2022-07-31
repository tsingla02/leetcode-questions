class Solution {
public:
    string reverseWords(string s) {
        int j = 0;
        int count = 0;
        for(int i = 0; i< s.size() ; i++)
        {
            if(s[i] == ' ')
            {
                count++;
            }
        }
        for(int i = 0; i< s.size() ; i++)
        {
            if(s[i] == ' ')
            {
                reverse(s.begin()+j, s.begin() + i);
                j = i+1;
                count--;
            }
            if(count== 0 )
            {
                reverse(s.begin()+j, s.end());
                break;
            }
        }
        return s;
    }
};