class Solution
{
    public:
        int myAtoi(string s)
        {
            vector<char> st;
            char sign = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] >= 48 && s[i] <= 57)
                    st.push_back(s[i]);
                else if (sign == 0 && s[i] == 45 && st.empty())
                {
                    sign = 45;
                }
                else if (sign == 0 && s[i] == 43 && st.empty())
                {
                    sign = 43;
                }
                else if (s[i] == 32 && st.empty() && sign == 0)
                    continue;
                else
                    break;
            }
           	//         int j = 0;
           	//         int k = 0;
           	//         int sum= 0;
           	//         vector < int>num;
           	//         while(j < st.size())
           	//         {
           	//             if(st[j]>=40 && st[j]<=47)
           	//             {

           	//             }
           	//             else
           	//             {
           	//                 num.push_back(st[j]-48);
           	//             }
           	//             j++;
           	//         }

           	//         for(int i = 0 ; i< num.size() ; i++)
           	//         {
           	//             cout<<num[i]<<" ";
           	//         }cout<<endl;
            long long int sum = 0;
           	// if(pow(10, st.size() - 1)<=INT_MIN || pow(10, st.size() - 1)>=INT_MAX)
           	//        break;
            for (int i = st.size() - 1; i >= 0; i--)
            {

                if (st[i] != 48 )
                {
                    if (pow(10, st.size() - 1 -i) >= INT_MAX)
                    {
                        if (sign == 45)
                        {
                            return INT_MIN;
                        }
                        else
                            return INT_MAX;
                    }
                }

                sum = sum + (st[i] - 48) *pow(10, st.size() - 1 - i);
            }
            if (sign == 45)
            {
                sum = -1 * sum;
            }
            if (sum <= INT_MIN)
                return INT_MIN;
            if (sum >= INT_MAX)
                return INT_MAX;
            return sum;
        }
};