/**
	Problem: Remove Nth Node From End of List
	Link:https://leetcode.com/problems/remove-nth-node-from-end-of-list/
**/

/**
	Given a linked list, remove the nth node from the end of list and return its head.
	For example,
	Given linked list: 1->2->3->4->5, and n = 2.
	After removing the second node from the end, the linked list becomes 1->2->3->5.
	Note:
	Given n will always be valid.
	Try to do this in one pass.
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//设置mark作为哨兵节点，用于应付边界情况
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode mark(0);
		mark.next = head;
		ListNode* p = &mark, *q = &mark, *temp;
		for(int i=0; i<n; i++)
			p = p->next;
		while(p->next){
			p = p->next;
			q = q->next;
		}
		p = q->next;
		q->next = p->next;
		delete p;
		return mark.next;
    }
};


