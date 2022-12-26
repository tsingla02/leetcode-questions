class Solution
{
    public:

        void merge(vector<int> &nums, int start, int last, int mid)
        {
            vector<int> ans(last - start + 1);
            int i = start;
            int j = mid + 1;
            int k = 0;
            while (i <= mid && j <= last)
            {
                if (nums[i] < nums[j])
                {
                    ans[k++] = nums[i++];
                }
                else
                {
                    ans[k++] = nums[j++];
                }
            }
            while (j <= last)
            {
                ans[k++] = nums[j++];
            }
            while (i <= mid)
            {
                ans[k++] = nums[i++];
            }

            for (int i = 0; i < last - start +1; i++)
            {
                nums[start + i] = ans[i];
            }
            // for(int i = 0 ; i<nums.size() ; i++)
            // {
            //     cout<<nums[i]<<" ";
            // }
            // cout << endl;
        }
    void mergesort(vector<int> &nums, int start, int last)
    {
        if (last <= start)
        {
            return;
        }

        int mid = start + (last - start) / 2;
        mergesort(nums, start, mid);
        mergesort(nums, mid + 1, last);
        merge(nums, start, last, mid);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size() - 1;
        mergesort(nums, 0, n);
        return nums;
    }
};