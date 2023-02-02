class Solution
{
    public:
        int countHillValley(vector<int> &nums)
        {
            int count = 0;
            for (int i = 1; i < nums.size() - 1; i++)
            {
                if (nums[i] > nums[i + 1] && nums[i] > nums[i - 1])
                    count++;
                else if (nums[i] < nums[i + 1] && nums[i] < nums[i - 1])
                    count++;
                else if (nums[i] == nums[i + 1])
                {
                    if (nums[i] < nums[i - 1])
                    {
                        while (nums[i] == nums[i + 1])
                        {
                            i++;
                            if (i == nums.size() - 1) break;
                        }
                        if (i != nums.size() - 1)
                        {
                            if (nums[i] < nums[i + 1])
                                count++;
                        }
                    }
                    else if (nums[i] > nums[i - 1])
                    {
                        while (nums[i] == nums[i + 1])
                        {
                            i++;
                            if (i == nums.size() - 1) break;
                        }
                        if (i != nums.size() - 1)
                        {
                            if (nums[i] > nums[i + 1])
                                count++;
                        }
                    }
                }
            }
            return count;
        }
};