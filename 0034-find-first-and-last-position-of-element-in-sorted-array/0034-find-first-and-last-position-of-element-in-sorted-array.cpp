class Solution
{
    public:
       	// void print(vector<int> &nums, int start, int end)
       	// {
       	//     for (int i = start; i <= end; i++)
       	//     {
       	//         cout << nums[i] << " ";
       	//     }
       	//     cout << endl;
       	// }
        vector<int> searchRange(vector<int> &nums, int target)
        {
            vector<int> no_ans = { -1,
                -1
            };
            vector<int> ans;
            if (nums.size() == 0) return no_ans;
            if (target > nums[nums.size() - 1]) return no_ans;
            if (target < nums[0]) return no_ans;
            if(nums.size() == 1)
                if(nums[0] == target)
                {
                    ans.push_back(0);
                    ans.push_back(0);
                    return ans;
                }

            long long int low = 0;
            
            long long int high = nums.size() - 1;
            long long int mid = (low + high) / 2;
            int t, y;
            while (low != high && low < high)
            {

                mid = (low + high) / 2;
                if (nums[mid] == target)
                {
                    t = mid;
                    y = mid;
                    break;
                }
                if (nums[mid] > target)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
               	// print(nums, low, high);
            }
            // cout << t << " " << y << endl;
            if (nums[t] == target)
            {
                while (nums[t] == target)
                {
                    t++;
                    if (t - 1 == nums.size() - 1)
                        break;
                }
                while (nums[y] == target)
                {
                    y--;
                    if (y + 1 == 0)
                        break;
                }
                ans.push_back(y + 1);
                ans.push_back(t - 1);
               	// cout<<y<<" "<< t;
                return ans;
            }
            else
            {
                return no_ans;
            }
        }
};