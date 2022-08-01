class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> mp;
        int t = 97;
        string s;
        for(int i = 0; i<key.size() ; i++)
        {
            if(key[i]==32)
            {
                continue;
            }
            else
            {
                if (mp.find(key[i]) != mp.end()) {
                    continue;
                }
                else
                {
                    mp[key[i]] = t;
                    t++;
                    if(t==123)
                        break;
                }
            }
            
        }
        for(int i = 0; i<message.size(); i++)
        {
            if(message[i] == 32)
            {
                s.push_back(32);
            }
            else
            {
                for(auto x : mp)
                {
                    // char ch = x.second;

                    if(message[i] == x.first)
                    {
                        s.push_back(x.second);
                    }

                }
            }
            
        }
        return s;
    }
};