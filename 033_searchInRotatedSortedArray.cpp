/**
	Problem: Search in Rotated Sorted Array
	Link:https://leetcode.com/problems/search-in-rotated-sorted-array/
	Reference:
**/

/**
	Suppose a sorted array is rotated at some pivot unknown to you beforehand.
	(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
	You are given a target value to search. If found in the array return its index, otherwise return -1.
	You may assume no duplicate exists in the array.
**/
 
class Solution {
public:
    int search(vector<int>& nums, int target) {
		int head = 0, tail = nums.size()-1;
		while(tail>=head){
			int mid = (tail + head) >> 1;
			if(nums[mid]==target)
				return mid;
			if(nums[head]>nums[tail]){
				if(nums[mid]>nums[head]){
					if(target>nums[mid])
						head = mid + 1;
					else if(target>=nums[head])
						tail = mid - 1;
					else
						head = mid + 1;
				}else{
					if(target<nums[mid])
						tail = mid - 1;
					else if(target>=nums[head])
						tail = mid - 1;
					else
						head = mid + 1;
				}
			}else{
				if(target<nums[mid])
					tail = mid - 1;
				else
					head = mid + 1;
			}
		}
		return -1;
    }
};


