class Solution
{
    public:

        bool checkInclusion(string s1, string s2)
        {
            if(s2.size()<s1.size())return false;
            unordered_map<char, int> st1;
            int size1 = s1.size();
            unordered_map<char, int> st2;
            for (int i = 0; i < size1; i++)
            {
                st1[s1[i]]++;
                st2[s2[i]]++;
            }
            
            if (st1 == st2) return true;
            if (st1 != st2 && s1.size() == s2.size()) return false;
           
            for (int i = s1.size(); i < s2.size(); i++)
            {
                st2[s2[i]]++;
                st2[s2[i - s1.size()]]--;
               	if(st2[s2[i-s1.size()]] == 0)st2.erase(s2[i-s1.size()]);
                //  for (auto it1 = st2.begin(); it1 != st2.end(); ++it1)
                //     cout << it1->first << "->" << it1->second << endl;
                // cout<<endl;
                
                if (st1 == st2) return true;
            }
            return false;
        }
};