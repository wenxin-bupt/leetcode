/**
	Problem: Merge k Sorted Lists
	Link:https://leetcode.com/problems/merge-k-sorted-lists/
**/

/**
	Merge k sorted linked lists and return it as one sorted list. 
	Analyze and describe its complexity.
**/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //根据外部排序算法，构造一个哈夫曼树得到的比较次数最少。
 //使用小根堆来做这件事情，即每次弹出两个最小的数列merge后将表长入堆，由此循环.
 //:-( 有种画蛇添足的感觉 WTF

 //标记list长度
 class LinkList{
public:
	ListNode *head;
	int length;
	LinkList(ListNode* p){
		head = p;
		length = 0;
		while(p){
			length++;
			p = p->next;
		}
	}
	LinkList(ListNode* p, int a){
		head = p;
		length = a;
	}
};

class Solution {
	
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.size()==0)
			return 0;
		vector<LinkList> collect;
		for(int i=0, max=lists.size(); i<max; i++){
			LinkList cache(lists[i]);
			collect.push_back(cache);
		}
		make_heap(collect.begin(), collect.end(), compare);
		while(collect.size()>1){
			LinkList a = collect.front();
			pop_heap(collect.begin(), collect.end(), compare);
			collect.pop_back();
			LinkList b = collect.front();
			pop_heap(collect.begin(), collect.end(), compare);
			collect.pop_back();
			LinkList c(subMerge(a.head,b.head), a.length+b.length);
			collect.push_back(c);
			push_heap(collect.begin(), collect.end(), compare);
		}
		return collect[0].head;
    }
	
private:

	ListNode* subMerge(ListNode* a, ListNode* b){
		ListNode head(0);
		ListNode* pointer = &head;
		while(a&&b){
			if(a->val>b->val){
				pointer->next = b;
				b = b->next;
			}else{
				pointer->next = a;
				a = a->next;
			}
			pointer = pointer->next;
		}
		if(a)
			pointer->next = a;
		if(b)
			pointer->next = b;
		return head.next;
	}
	
	static bool compare(const LinkList p, const LinkList q){
		return p.length>q.length;
	}
};



