class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)return true;
        long long int start = 0 ; 
        long long int last = num;
        vector<long long int> ans;
        ans.push_back(0);
        while(last>start)
        {
            long long int mid = start + (last-start)/2;
            cout<<mid<<" ";
            if(ans[ans.size()-1]==mid)return false;
            ans.push_back(mid);
            
            if(mid*mid == num)
            {
                return true;
            }
            else if(mid*mid > num)
            {
                last = mid;
            }
            else if(mid*mid < num)
            {
                start = mid;
            }
        }
        if(last<start)
        {
            return false;
        }
        return false;
    }
};