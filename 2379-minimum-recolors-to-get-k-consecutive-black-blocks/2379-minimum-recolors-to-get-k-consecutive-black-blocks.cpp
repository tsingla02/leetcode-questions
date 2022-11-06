class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        queue<char> s;
        unordered_map<char,int>mp;
        int mx = 0;
        for(int i = 0 ; i< blocks.size() ; i++)
        {
            char t = blocks[i];
            s.push(t);
            if(t=='B')
            {
                mp['b']++;
            }
            else
            {
                mp['w']++;
            }
            
            
            if(s.size() < k)
            {
                
                continue;
            }
            
            else
            {
                mx = max(mx,mp['b']);
                if(s.front() == 'B')
                {
                    mp['b']--;
                }
                else
                {
                    mp['w']--;
                }
                s.pop();
            }
        }
        return k-mx;
    }
};