class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int k = 2;
        for(int i=0; i< nums.size() ; i++)
        {
            pq.push(nums[i]);
            if(pq.size() >2)
            {
                pq.pop();     
            }
            
            
        }
        int c;
        c = pq.top();
        // cout<<c<<endl;
        pq.pop();
        int c1;
        // cout<<c1<<endl;
        c1 = pq.top();
        return (c-1)*(c1-1);
    }
};