/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> st;
        while(head != NULL)
        {
            if(st.find(head) == st.end())
            {
                st.insert(head);
            }
            else
            {
                return true;
            }
            
            head = head->next;
        }
        return false;
    }
};