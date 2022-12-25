class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin() , nums.end());
        // sort(queries.begin() , queries.end());
        stack<int>ans;
        int t = nums.size();
        int sum = accumulate(nums.begin() , nums.end(), 0);
        
        for(int i = queries.size()-1 ; i>=0 ; i--)
        {
            // int j = 0;
            int t = nums.size();
            sum = accumulate(nums.begin() , nums.end(), 0);
            while(sum>queries[i])
            {
                // cout<<sum<<" ";
                sum = sum - nums[t-1];
                t--;
            }
            ans.push(t);
            // cout<<endl<<":"<<t<<endl;
        }
        vector<int> ansl;
        int ti = ans.size();
        for(int i = 0 ; i< ti ; i++)
        {
            ansl.push_back(ans.top());
            ans.pop();
        }
        return ansl;
    }
};