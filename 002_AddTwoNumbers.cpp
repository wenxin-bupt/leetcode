//2016 1 1 18:00

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	#define SOLUTION_1
	
	#ifdef SOLUTION_1
	
	// 44ms concise solution
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode head(0), *p = &head;
		int extra = 0;
		while (l1 || l2 || extra) {
			if (l1) extra += l1->val, l1 = l1->next;
			if (l2) extra += l2->val, l2 = l2->next;
			p->next = new ListNode(extra % 10);
			extra /= 10;
			p = p->next;
		}
		return head.next;
	}
	
	#else
	
	//40ms solution
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode head(0), *p = &head;
		int extra = 0;
		while (l1 && l2) {
			extra += l1->val + l2->val;
			p->next = new ListNode(extra % 10);
			extra /= 10; p = p->next; l1 = l1->next; l2 = l2->next;
		}
		while (l1) {
			extra += l1->val;
			p->next = new ListNode(extra % 10);
			extra /= 10; p = p->next; l1 = l1->next;
		}
		while (l2) {
			extra += l2->val;
			p->next = new ListNode(extra % 10);
			extra /= 10; p = p->next; l2 = l2->next;
		}
		if (extra) p->next = new ListNode(1);
		return head.next;
	}

//my ugly code
//time cost 40ms
/*
		ListNode  *p,*q, *a;
		int flag = 0;
		int temp;
		bool firsttime = true;
		while(l1&&l2){

			temp = l1->val + l2->val + flag;
			if(temp>9){
				flag = 1;
				temp = temp % 10;
			}else{
				flag = 0;
			}
			a = new ListNode(temp);
			if(firsttime){
				q = a;
				p = a;
				firsttime = false;
			}else{
				p->next = a;
				p = a;
			}

			l1 = l1->next;
			l2 = l2->next;

			if((!l1&&!l2)&&flag==1){
				a  = new ListNode(1);
				p->next  = a;
			}
		}

		while(l1){
			
			temp = l1->val + flag;
			if(temp>9){
				flag = 1;
				temp = temp % 10;
			}else{
				flag = 0;
			}
			a = new ListNode(temp);
			if(firsttime){
				q = a;
				p = a;
				firsttime = false;
			}else{
				p->next = a;
				p = a;
			}

			l1 = l1->next;

			if((!l1)&&flag==1){
				a  = new ListNode(1);
				p->next  = a;
			}
		}

		while(l2){
			
			temp = l2->val + flag;
			if(temp>9){
				flag = 1;
				temp = temp % 10;
			}else{
				flag = 0;
			}
			a = new ListNode(temp);
			if(firsttime){
				q = a;
				p = a;
				firsttime = false;
			}else{
				p->next = a;
				p = a;
			}

			l2 = l2->next;

			if((!l2)&&flag==1){
				a  = new ListNode(1);
				p->next  = a;
			}
		}
		return q;

    }
*/

};

