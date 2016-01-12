/**
	Problem:Merge Sorted Array
	Link:https://leetcode.com/problems/merge-sorted-array/
	Time complexity:O(m+n)
	Space complexity:O(m)
**/

/**
	Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

	Note:
	You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
	The number of elements initialized in nums1 and nums2 are m and n respectively.
**/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> cache(nums1.begin(), nums1.begin()+m);
		int p=0, q=0, i=0;
		while(p<m&&q<n){
			while(p<m&&cache[p]<=nums2[q]) 
				nums1[i++] = cache[p++];
			while(q<n&&nums2[q]<cache[p]) 
				nums1[i++] = nums2[q++];
		}
		while(p<m)
			nums1[i++] = cache[p++];
		while(q<n)
			nums1[i++] = nums2[q++];
		return;
    }
};