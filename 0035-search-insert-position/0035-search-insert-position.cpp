class Solution
{
    public:
    // void print(vector<int> &nums, int s , int e)
    // {
    //     for(int i = s; i<= e ; i++)
    //     {
    //         cout<<nums[i]<<" ";
    //     }
    //     cout<<endl;
    // }
    int searchInsert(vector<int> &nums, int target)
    {
        if (nums[0] > target)
            return 0;

        if (nums[nums.size() - 1] < target)
            return nums.size();
        int mid = (0 + nums.size() - 1) / 2;
        int low = 0;
        int high = nums.size() - 1;
        while (low != high && low<high)
        {
            mid = (low + high) / 2;
            
            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
            // print(nums,low,high);
        }
        if(nums[low]<target)
            return low+1;
        else
            return low;
    }
};