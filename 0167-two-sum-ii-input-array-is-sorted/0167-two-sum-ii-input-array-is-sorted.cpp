class Solution
{
    public:
        vector<int> twoSum(vector<int> &numbers, int target)
        {
            vector<int> ans;
            int high = numbers.size() - 1;
            int low = 0;
            // int sum = ;
            while (low < high)
            {
                if (target == numbers[low] + numbers[high])
                {
                    ans.push_back(low + 1);
                    ans.push_back(high + 1);
                    break;
                }
                else if (numbers[low] + numbers[high] > target)
                {
                    high--;
                }
                else
                {
                    low++;
                }
            }
            return ans;
        }
};