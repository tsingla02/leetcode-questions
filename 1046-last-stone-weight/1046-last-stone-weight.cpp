class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i = 0 ; i<stones.size() ; i++ )
            {
                if(stones[i]!= 0)
                {
                    pq.push(stones[i]);
                }
            }
        while(pq.size() > 1)
        {
            
            int c = pq.top(); 
            pq.pop();
            int c1 = pq.top();
            pq.pop();
            pq.push(c-c1);
        }
        return pq.top();
    }
};