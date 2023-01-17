class Solution {
public:
    
    int mySqrt(int x) {
        if(x == 0)return 0;
        if(x == 1)return 1;
        int start = 0;
        int last = x;
        long long int mid = start + (last-start)/2;
        while(start<last)
        {
            mid = start + (last-start)/2;
            if(mid*mid == x)
                return mid;
            if(mid*mid < x && (mid+1)*(mid+1)>x)
                return mid;
            else if(mid*mid > x)
            {
                last = mid;
            }
            else if(mid*mid < x)
            {
                start = mid;
            }
        }
        return mid;
    }
};