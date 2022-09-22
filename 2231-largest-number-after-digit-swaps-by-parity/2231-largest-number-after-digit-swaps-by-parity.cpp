class Solution {
public:
    long long int largestInteger(int num) {
        long long num2 = num;
        priority_queue<long long> even;
        priority_queue<long long> odd;
        long long int t =1;
        vector<long long> all;
        long long count = 0;
        while(num)
        {
            num = num/ 10;
            count++;
        }
        long long c = count;
        t =1 ;
        while(c--)
        {
            t = t *10;
        }
        t = t/10;
        while(count--)
        {
            all.push_back(num2/t);
            if((num2/t)%2 == 0)
            {
                even.push(num2/t);
            }
            else
            {
                odd.push(num2/t);
            }
            num2 = num2 % t;
            t =t /10;
            
        }
        vector<int> ans;
        for(long long i = 0 ; i< all.size() ; i++)
        {
            if(all[i]%2 == 0)
            {
                ans.push_back(even.top());
                even.pop();
            }
            else
            {
                ans.push_back(odd.top());
                odd.pop();
            }
        }
        int sum = 0;
        int s = ans.size()-1;
        int p=1;
        while(s--)
        {
            p = p * 10;
        }
        // cout << p <<endl;
        for(long long i = 0; i< ans.size() ; i++)
        {
            sum = sum + ans[i]*p;
            p = p/10;
            // cout<<ans[i] <<" ";
        }
        
        return sum;
    }
    
};