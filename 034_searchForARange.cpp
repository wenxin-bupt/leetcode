/**
	Problem: Search for a Range
	Link:https://leetcode.com/problems/search-for-a-range/
	Reference:https://leetcode.com/discuss/18242/clean-iterative-solution-binary-searches-with-explanation
**/

/**
	Given a sorted array of integers, find the starting and ending position of a given target value.
	Your algorithm's runtime complexity must be in the order of O(log n).
	If the target is not found in the array, return [-1, -1].
	For example,
	Given [5, 7, 7, 8, 8, 10] and target value 8,
	return [3, 4].
**/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		int i = 0, j = nums.size() - 1;
		vector<int> ret(2, -1);
		while (i < j){
			int mid = (i + j) / 2;
			if (nums[mid] < target) 
				i = mid + 1;
			else 
				j = mid;
		}
		if (nums[i]!=target) 
			return ret;
		else 
			ret[0] = i;

		j = nums.size() - 1; 
		while (i < j){
			int mid = (i + j) / 2  + 1;   
			if (nums[mid] > target) 
				j = mid - 1;  
			else 
				i = mid;               
		}
		ret[1] = j;
		return ret; 
	}
};



