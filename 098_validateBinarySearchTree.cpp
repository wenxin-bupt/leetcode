/**
	Problem:Validate Binary Search Tree
	Link:https://leetcode.com/problems/validate-binary-search-tree/
	Time complexity:O(n)
	Space complexity:O(1)
**/

/**
	Given a binary tree, determine if it is a valid binary search tree (BST).
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
 
//非递归中序遍历
//Runtime 16ms.
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<TreeNode*> stack(1000,0);
		vector<int> cache(10000,0);
		int sP = -1;
		int cP = 0;
		TreeNode *traveler;
		traveler = root;
		while(traveler||sP!=-1){
			if(traveler){
				stack[++sP] = traveler;
				traveler = traveler->left;
			}else{
				traveler = stack[sP--];
				cache[cP++] = traveler->val;
				traveler = traveler->right;
			}
		}
		if(cP<2)
			return true;
		for(int i=1; i<cP; i++){
			if(cache[i]<=cache[i-1])
				return false;
		}
		return true;
    }
};