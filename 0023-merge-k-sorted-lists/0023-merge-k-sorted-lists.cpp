/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*> , vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;

        if(lists.size() == 0){
            ListNode* list = NULL;
            return list;}
        for(int i = 0 ; i< lists.size() ; i++)
        {
            if(lists[i] != NULL)
                pq.push(make_pair(lists[i]->val,lists[i]));
        }
        if(pq.empty())
        {
            ListNode* list = NULL;
            return list;
        }
        ListNode* head;
        ListNode* cur;
        ListNode* temp = head;
        int f_head = 0;
        while(!pq.empty())
        {
            if(f_head == 0){
                head = pq.top().second;
                cur = head->next;
                head->next = NULL;
                temp = head;
                pq.pop();
                if(cur)
                {
                    pq.push(make_pair(cur->val, cur));
                }
                f_head = 1;
            }
            else
            {
                temp->next = pq.top().second;
                temp = temp->next;
                cur = temp->next;
                temp->next = NULL;
                pq.pop();
                if(cur)
                {
                    pq.push(make_pair(cur->val,cur));
                }
            }
            
        }
        return head;
    }
};