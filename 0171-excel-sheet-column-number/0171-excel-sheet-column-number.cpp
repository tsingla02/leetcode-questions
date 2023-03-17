class Solution {
public:
    int titleToNumber(string columnTitle) {
        // vector<long long int> end;
        // end.push_back(0);
        // for(int i = 1 ; i<= 7 ; i++)
        // {
        //     end.push_back(26*(end[i-1])+26);
        //     cout<<end[i]<<endl;
        // }
        int t = 0;
        long long int sum = 0;
        for(int i = 0 ; i< columnTitle.size(); i++)
        {
            t = columnTitle[i]-64;
            sum = sum*26+t;
        }
        return sum;
    }
};