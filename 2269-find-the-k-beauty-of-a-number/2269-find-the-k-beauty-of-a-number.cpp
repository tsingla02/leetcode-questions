class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int n = num;
        int count = 0;
        while(num>0)
        {
            num = num/10;
            count++;
        }
        num = n;
        
        
        vector<int> arr;
        
        while(count--)
        {
            int t = num/pow(10,count);
            int x =pow(10,count);
            num = num % x;
            arr.push_back(t);
            
        }
        num = n;
        long int sum = 0;
        count = 0;
        for(int i =0 ; i< arr.size() ; i++)
        {
            sum = sum + arr[i];
            
            long int u = pow(10,k);
            if(sum>=u)
            {
                // cout<<"tushar";
                sum = sum%u;
                
            }
            
            
            if(i>=k-1)
            {
                
                if (sum == 0)
                {
                    continue;
                }
                else
                {
                    if(num%sum==0)
                    {
                        count++;
                    }
                }
                
                
            }
            
            int tr = pow (10,9);
            cout<<sum<<endl;
            
            sum = sum*10;
            
            
        }
        return count;
    }
};