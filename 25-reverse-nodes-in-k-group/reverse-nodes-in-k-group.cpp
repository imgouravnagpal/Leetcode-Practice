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
ListNode *reverse(ListNode *head)
{
    ListNode *prev=NULL;
    ListNode *current=head;
    ListNode *next=NULL;
    
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
        {
            return NULL;
        }
      ListNode* temp = head;
        int i= 0;
        while(i<k-1&&head!=NULL)
        {
            head= head->next;
            i++;
        }
        if(head!=NULL)
        {
            
            ListNode* a = head->next;
            head->next = NULL;
            ListNode *ans = reverse(temp);
            temp->next = reverseKGroup(a,k);
            return ans;
        }
        
    
        
        return temp;
        
            
        
    }
};