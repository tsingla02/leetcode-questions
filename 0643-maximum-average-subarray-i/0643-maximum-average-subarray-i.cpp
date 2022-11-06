class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double mx = INT_MIN;
        double ct = 0.0;
        
        for(int i = 0 ; i< k ; i++)
        {
            ct = ct + nums[i];
        }
        mx = max (mx, ct/k);
        for(int i = k ; i< nums.size() ; i++)
        {
            ct = ct + nums[i];
            ct = ct - nums[i-k];
            mx = max (mx, ct/k);
        }
        return mx;
    }
};