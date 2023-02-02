class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int mid;
        int start = 0;
        int end = nums.size()-1;
        
        while(start<end-1)
        {
            mid = start+(end-start)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                return mid;
            else if(nums[mid]>nums[mid-1])
            {
                start = mid+1;
            }
            else 
                end = mid-1;
        }
        if(nums[start]>nums[end])return start;
        else
            return end;
    }
};