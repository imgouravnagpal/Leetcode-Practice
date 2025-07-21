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
    ListNode* reverse(ListNode* head)
    {
        
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(current!=NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k==0)
        {
            return head;
        }
        
        ListNode* temp = head;
        int length = 0;
        while(temp != NULL)
        {
            temp = temp->next;
            length++;
        }
        temp = head;
        int count = 1;
        
        k = k % length;
       
        if(k==0)
        {
            return head;
        }
        head = reverse(head);
        temp = head;
        while(temp!=NULL && count<k)
        {
            temp = temp->next;
            count++;
        }
        
        
        
        if(temp!=NULL )
        {
            ListNode* next = temp->next;
            temp->next=NULL;
            ListNode* prev= head;
            head = reverse(head);
            prev ->next = reverse(next);
        }
        return head;
    }
};