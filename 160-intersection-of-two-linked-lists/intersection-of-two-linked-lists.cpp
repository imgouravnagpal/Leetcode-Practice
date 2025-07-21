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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	ListNode* i = headA;
	ListNode* j = headB;

	while (i != j) {
		if (i == NULL)
			i = headB;
		if (j == NULL)
			j = headA;

		if (i == j)
			break;

		i = i->next;
		j = j->next;
	}

	return i;
}
};