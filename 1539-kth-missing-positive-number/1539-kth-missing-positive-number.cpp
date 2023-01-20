class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(k<arr[0])
            return k;
        int missed_count_prev = arr[0]-1;
        int missed_count_after = missed_count_prev;
        for(int i = 1; i< arr.size() ;i++)
        {
            missed_count_after += arr[i]-arr[i-1]-1;
            if(missed_count_prev < k && missed_count_after >=k)
            {
                k = k - missed_count_prev;
                return arr[i-1]+k;
            }
            missed_count_prev = missed_count_after;
        }
        
        return arr[arr.size()-1]+k - (missed_count_prev);
    }
};