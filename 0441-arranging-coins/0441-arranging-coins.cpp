class Solution {
public:
    int arrangeCoins(int n) {
        // n = 2*n;
        int start = 0;
        int last = n;
        long long int mid;
        while(start<=last)
        {
            mid = start + (last - start)/2;
            long long int t = (mid*mid + mid)/2;
            
            if(t == n)
            {
                return mid;
            }
            else if((mid*mid + mid)/2 >n &&( (mid-1)*(mid-1) + (mid-1) )/2<n)
                return mid-1;
            else if(t>n)
            {
                last = mid-1;
            }
            
            else
            {
                start = mid+1;
            }
        }
        return mid;
    }
};