class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long long int sum = 0;
        for(long long int i = 0 ; i < k ; i++)
        {
            sum = sum + arr[i];
        }
        
        long long int avg = 0;
        long long int count = 0;
        for(long long int i = k ; i < arr.size() ; i++)
        {
            cout<<sum<<endl;
            avg = sum/k;
            if(avg >= threshold)
                count++;
            sum = sum - arr[i-k];
            sum = sum + arr[i];
        }
        avg = sum/k;
        if(avg >= threshold)
            count++;
        return count;
    }
    
};