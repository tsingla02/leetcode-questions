class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector <string> t = {"Gold Medal" , "Silver Medal" , "Bronze Medal"};
        unordered_map<int,int> mp;
        for(int i = 0 ; i< score.size() ; i++)
        {
            mp[i] = score[i];
        }
        priority_queue<pair<int,int>> pq;
        for(auto i : mp)
        {
             pq.push(make_pair(i.second, i.first));
        }
        vector<pair<int,int>> last;
        int k = 1;
        cout<<pq.size()<<endl;
        int n = pq.size();
        for(int i=0; i<n;i++)
        {
            pair<int,int> pr = pq.top();
            last.emplace_back(pr.second ,k);
            pq.pop();
            k++;
        }
        // cout<<k<<endl;
        // cout<<last.size()<<endl;
        for(int i = 0 ; i< last.size() ; i++)
        {
            cout<<last[i].first<<" ";
        }
        priority_queue<pair<int,string>, vector<pair<int,string>> , greater<pair<int,string>>> pqa;
        for(int i= 0 ; i< last.size() ; i++)
        {
            if(i==0)
            {
                pqa.push(make_pair(last[i].first , "Gold Medal"));
            }
            else if(i==1)
            {
                pqa.push(make_pair(last[i].first , "Silver Medal"));
            }
            else if(i==2)
            {
                pqa.push(make_pair(last[i].first , "Bronze Medal"));
            }
            else
            {
                pqa.push(make_pair(last[i].first , to_string(i+1)));
            }
        }
        vector<string> ans1;
        for(int i = 0 ; i< last.size() ; i++)
        {
            ans1.push_back(pqa.top().second);
            pqa.pop();
        }
        return ans1;
    }
};