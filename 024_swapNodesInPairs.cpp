/**
	Problem: Swap Nodes in Pairs
	Link:https://leetcode.com/problems/swap-nodes-in-pairs/
**/

/**
	Given a linked list, swap every two adjacent nodes and return its head.
	For example,
	Given 1->2->3->4, you should return the list as 2->1->4->3.
	Your algorithm should use only constant space. 
	You may not modify the values in the list, only nodes itself can be changed.
**/

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
    ListNode* swapPairs(ListNode* head) {
		ListNode realHead(0);
		realHead.next = head;
		ListNode *mark = &realHead, *pointer = head;
		while(pointer&&pointer->next){
			mark->next = pairReverse(pointer);
			mark = pointer;
			pointer = pointer->next;
		}
		return realHead.next;
    }
private:
	ListNode* pairReverse(ListNode* left){
		ListNode* right = left->next;
		left->next = right->next;
		right->next = left;
		return right;
	}
};

