class Solution {
public:
    void insert(vector<int>& nums , priority_queue<int , vector<int> , greater<int>>& pq)
    {
        for(int i = 0 ; i< nums.size() ; i++)
        {
            if(nums[i] != 0)
            {
                pq.push(nums[i]);
            }
        }
    }
    int minimumOperations(vector<int>& nums) {
        priority_queue<int , vector<int> , greater<int>> pq;
        int count = 0;
        insert(nums, pq);
        while(!pq.empty())
        {
            while(!pq.empty())
            {
                pq.pop();
            }
            insert(nums, pq);
            int c = pq.top();
            count++;
            for(int i =0 ; i< nums.size() ; i++)
            {
                if(nums[i] != 0 && nums[i]>0)
                {
                    nums[i] = nums[i]-c;
                }
            }
        }
        if(count == 0)
        {
            return count;
        }
        return count-1;
        
    }
};