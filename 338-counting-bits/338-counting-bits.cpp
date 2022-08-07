class Solution {
public:
  // Online C++ compiler to run C++ program online
    

    int binary(int t)
    {
        if(t==0)
            return 0;
        int divi = t;
        int c=0;
        stack<int> q;
        while(divi >=2)
        {
            if(divi%2 == 0)
            {
                q.push(0);
            }
            else
            {
                q.push(1);
            }
            divi = divi/2;

        }
        q.push(1);
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.top());
            q.pop();
        }
        for(int i = 0; i<ans.size() ; i++ )
        {
            if(ans[i] == 1)
                c++;
        }
        return c;
    }
    // vector<int> countBits(int n) {
    //     return binary(n);
    // }
    
    
    
    vector<int> countBits(int n) {
        vector<int>ans;
        int t = 0;
        while(t<=n)
        {
            ans.push_back(binary(t));
            t++;
        }
        return ans ;
    }
};