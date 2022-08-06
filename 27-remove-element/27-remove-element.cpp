class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        int t = nums.size();
        for(int i = 0 ; i< nums.size() ; i++)
        {
            if(nums[i] == val)
            {
                
                for(int j = i; j< nums.size()-1 ; j++)
                {
                    nums[j] = nums[j+1]; 
                }
                 i = i-1;
                nums.pop_back();
                // t = t-1;
               
            }
            else
            {
                count++;
            }
            
        }
        return count;
    }
};