// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
    public:
        int firstBadVersion(int n)
        {
            long long int low = 0;
            long long int high = n;
            long long int mid = n/2;
            while (low != high && low < high)
            {
                
                mid = (low + high) / 2;
                if (isBadVersion(mid) == true)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
                
            }
            if(isBadVersion(low) == true)
            {
                return low;
            }
            else
                return low+1;
        }
};