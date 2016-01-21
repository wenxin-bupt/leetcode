/**
	Problem: Remove Element
	Link:https://leetcode.com/problems/remove-element/
**/

/**
	Given an array and a value, remove all instances of that value in place and return the new length.
	The order of elements can be changed. It doesn't matter what you leave beyond the new length.
**/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		if(nums.size()==0)
		    return 0;
		int p = 0, q = nums.size()-1;
		while(q>=0&&q>p&&nums[q]==val)
			q--;
		for(; p<=q; p++){
			if(nums[p]==val){
				while(q>=0&&q>p&&nums[q]==val)
					q--;
				swap(nums[p], nums[q]);
				q--;
			}
		}
		nums.resize(++q);
		return nums.size();
    }
};

