class Solution {
public:
    int specialArray(vector<int>& a) {
       int n = a.size();
        sort(a.rbegin(), a.rend());
        int ans = -1;
        for(int x = 0; x<n;x++) {
            if(a[x]>=x+1) {
                if(x+1>=n || !(a[x+1]>=x+1)) {
                    ans = x+1;    
                }
            }
        }
        return ans;	
    }
};