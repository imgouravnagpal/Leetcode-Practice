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
    bool helper(ListNode* &head1 , ListNode* head2)
    {
        if(head2 == NULL)
        {
            return head2;
        }
        if(head1 == NULL)
        {
            return true;
        }
        bool ans = helper(head1,head2->next);
        if(head1->val != head2->val)
        {
            return false;
        }
        else{
            head1 = head1->next;
            return ans || (head1==NULL);
        }

    }
    bool isPalindrome(ListNode* head) {
        return helper(head,head);
    }
};