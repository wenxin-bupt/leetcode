/**
	Problem:Sum Root to Leaf Numbers
	Link:https://leetcode.com/problems/sum-root-to-leaf-numbers/
	Time complexity:O(n)
**/

/**
	Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
	An example is the root-to-leaf path 1->2->3 which represents the number 123.
	Find the total sum of all root-to-leaf numbers.
	
	For example,
		1
	   / \
	  2   3
	The root-to-leaf path 1->2 represents the number 12.
	The root-to-leaf path 1->3 represents the number 13.
	Return the sum = 12 + 13 = 25.
**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//后序遍历，使用数组做的自制栈更顺手些
class Solution {
public:
    int sumNumbers(TreeNode* root) {
		vector<TreeNode*> stack(20);
		int pointer = -1;
		int sum = 0;
		if(!root)
			return sum;
		stack[++pointer] = root;
		bool flag = false;
		while(pointer!=-1){
			if(flag){
				if(!stack[pointer]->right||stack[pointer]->right == stack[pointer+1]){
					pointer--;
					flag = true;
				}else{
					stack[pointer+1] = stack[pointer]->right;
					pointer++;
					flag = false;
				}
			}else{
				while(stack[pointer]->left){
					stack[pointer+1] = stack[pointer]->left;
					pointer++;
				}
				if(stack[pointer]->right){
					stack[pointer+1] = stack[pointer]->right;
					pointer++;
				}else{
					int m = 0;
					for(int i = 0; i<=pointer; i++){
						m = m*10 + stack[i]->val;
					}
					sum += m;
					pointer--;
					flag = true;
				}
			}
		}
		return sum;
    }
};