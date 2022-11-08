class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i< arr.size() ; i++)
        {
            mp[arr[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto x:mp)
        {
            pq.push(make_pair(x.second, x.first));
        }
        int sum = 0 ;
        int count = 0;
        while(sum < arr.size()/2 && !pq.empty())
        {
            sum = sum + pq.top().first;
            cout<<pq.top().second<<endl;
            pq.pop();
            count++;
        }
        return count;
    }
};