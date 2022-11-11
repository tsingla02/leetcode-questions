class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int flag1 = 0;
        int flag2 = 0;
        if(nums.size() == 1)
            return true;
        for(int i = 0 ; i< nums.size()-1 ; i++)
        {
            if (nums[i+1]>= nums[i])
            {
                continue;
            }
            else
                flag1 = 1;
        }
        for(int i = 0 ; i< nums.size()-1 ; i++)
        {
            if (nums[i+1]<= nums[i])
            {
                continue;
            }
            else
                flag2 = 1;
        }
        if(flag1 == 1 && flag2 == 1)
            return false;
        return true;
    }
};