class Solution
{
    public:
    void print(vector<int> &nums, int s, int e)
    {
        for(int i = s ; i<=e; i++)
        {
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
        int binarysearch(vector<int> &nums, int s,int e,int k)
        {
            print(nums,s,e);
            if (s > e)
            {
                return -1;
            }
            int mid = (s + e) / 2;
            if (nums[mid] == k)
                return mid;
            if (nums[mid] > k)
            {
                return binarysearch(nums, s, mid - 1, k);
            }
            else
            {
                return binarysearch(nums, mid + 1, e, k);
            }
        }
    int search(vector<int> &nums, int target)
    {
        int ans = binarysearch(nums, 0, nums.size() - 1, target);
        return ans;
    }
};