/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        typedef pair<int, ListNode*> pi;
    ListNode* sortList(ListNode *head)
    {
        if (head == NULL) return head;
        priority_queue<pi, vector < pi>, greater < pi>> q;
        while (head != NULL)
        {
            q.push(make_pair(head->val, head));
            head = head->next;
        }
        ListNode *ans = q.top().second;
        while (!q.empty())
        {
            ListNode *temp = q.top().second;
            q.pop();
            temp->next = q.top().second;
            temp = temp->next;
            temp->next = NULL;
        }
        return ans;
    }
};