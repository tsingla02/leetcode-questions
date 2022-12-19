//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node* fast = head;
        Node*slow = head;
        int count=0;
        Node*c = head;
        while(c)
        {
            c = c->next;
            count++;
        }
        stack<int> st;
        while(fast != NULL && fast->next!= NULL)
        {
            st.push(slow->data);
            slow = slow ->next;
            fast= fast->next->next;
        }
        if(count%2 == 0)
        {
            int t;
            while(slow)
            {
                t = st.top();
                if(t != slow->data)
                {
                    return 0;
                }
                else
                {
                    st.pop();
                    slow = slow->next;
                    continue;
                }
            }
        }
        else
        {
            slow = slow->next;
            int t;
            while(slow)
            {
                t = st.top();
                if(t != slow->data)
                {
                    return 0;
                }
                else
                {
                    st.pop();
                    slow = slow->next;
                    continue;
                }
            }
        }
        return 1;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends