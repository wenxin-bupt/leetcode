/**
	Problem:Binary Tree Level Order Traversal
	Link:https://leetcode.com/problems/binary-tree-level-order-traversal/
	Time complexity:O(n)
**/

/**
	Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
	For example:
	Given binary tree {3,9,20,#,#,15,7},
		3
	   / \
	  9  20
		/  \
	   15   7
	return its level order traversal as:
	[
	  [3],
	  [9,20],
	  [15,7]
	]
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
//层序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		queue<TreeNode*> que1, que2, *father, *child;
		vector<int> cache;
		int numCache;
		father = &que1;
		child = &que2;
		if(!root)
			return res;
		father->push(root);
		while(!father->empty()){
			while(!father->empty()){
				numCache = father->front()->val;
				cache.push_back(numCache);
				if(father->front()->left)
					child->push(father->front()->left);
				if(father->front()->right)
					child->push(father->front()->right);
				father->pop();
			}
			swap(father, child);
			res.push_back(cache);
			cache.clear();
		}
		return res;
    }
};