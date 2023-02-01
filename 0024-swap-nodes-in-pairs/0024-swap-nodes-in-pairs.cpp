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
    ListNode* swap(ListNode* node)
    {
        if(node==NULL)return node;
        if(node->next == NULL)return node;
        ListNode* temp = node;
        ListNode* temp1 = node->next;
        ListNode* temp2 = node->next->next;
        temp1->next = temp;
        temp->next = temp2;
        node = temp1;
        return node;
    }
    ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL)return head;
        if(head->next == NULL)return head;
        ListNode* tamp = NULL;
        ListNode* temp5 = NULL;
        temp5 = head;
        while(head!=NULL && head->next!=NULL)
        {
            
            if(tamp == NULL){
                head = swap(head);
                tamp = head;
            }
            else
            {
                head = swap(head);
                temp5->next = head;
            }
            
            if(head->next== NULL)
            {
                break;
            }
            temp5 = head->next;
            head=head->next->next;
        }
        return tamp;
    }
};