class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int count = 0;
        int num = x;
        while(x)
        {
            count++;
            x =x/10;
        }
        vector<int> d;
        int t = pow(10,count-1);
        for(int i = 0 ; i< count ; i++)
        {
            d.push_back(num/t);
            num = num % t;
            t = t / 10;
            
        }
        int flag = 0;
        for(int i = 0 ; i< count/2 ; i++)
        {
            if(d[i]!=d[d.size()-1-i])
            {
                flag = 1;
            }
        }
        if(flag == 1)return false;
        return true;
    }
};