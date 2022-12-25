class Solution {
public:
    int reverse(int x) {
        vector<long long int> ans;
        while(x)
        {
            long long int t = x%10;
            // cout<<t<<" ";
            ans.push_back(t);
            x = x /10;
        }
        // cout<<endl;
        long long int size = ans.size();
        // cout<<size<<endl;
        long long int sum=0;
        for(int i = 0 ; i < ans.size() ; i++)
        {
            sum = sum+ans[i]*pow(10,size-1);
            // cout<<sum<<endl;
            size = size-1;
        }
        
        if (sum>(pow(2,31)-1) || sum< -(pow(2,31)))
            return 0;
        return sum;
    }
};