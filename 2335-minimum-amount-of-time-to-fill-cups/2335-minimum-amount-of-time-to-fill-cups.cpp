class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for(int i = 0 ; i < amount.size() ; i++)
        {
            if(amount[i] != 0)
            {
                pq.push(amount[i]);
            }
        }
        if(pq.size() == 0)
        {
            return 0;
        }
        
        int count =0;
        while(pq.size() > 1)
        {
            int temp1 = pq.top();
            pq.pop();
            int temp2 = pq.top();
            pq.pop();
            temp1 = temp1 - 1;
            temp2 = temp2 -1;
            if(temp1 != 0)
            {
                pq.push(temp1);
            }
            if(temp2 != 0)
            {
                pq.push(temp2);
            }
            count++;
        }
        if(pq.size() == 1)
        {
            count = count + pq.top();
        }
        
        return count;
    }
};