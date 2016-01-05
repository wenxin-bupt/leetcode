//2016 1 5 17:22

/**
	Problem: Median of Two Sorted Arrays
	Link:https://leetcode.com/problems/median-of-two-sorted-arrays/
	Reference:https://leetcode.com/discuss/15790/share-my-o-log-min-m-n-solution-with-explanation
	Time complexity:O(log(m+n))
	Space complexity:O(1)
	Runtime:44ms
**/
/**
	Requirements:
	There are two sorted arrays nums1 and nums2 of size m and n respectively. 
	Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
**/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int m = nums1.size();
			int n = nums2.size();
			if(m > n) 
				return findMedianSortedArrays(nums2, nums1);
			int i = 0, j = 0;
			int imin = 0, imax = m;
			int mid = (m + n + 1)>>1;			
			while(imin<=imax){
				i = (imin + imax)>>1;
				j = mid - i;
				if (i<m&&j>0&&nums2[j -1]>nums1[i])
					imin = i + 1;
				else if(i>0&&j<n&&nums1[i - 1]>nums2[j])
					imax = i - 1;
				else
					break;
			}
			int num1;
			if (!i) 
				num1 = nums2[j - 1];
			else if (!j)
				num1 = nums1[i - 1]; 
			else 
				num1 = max(nums1[i - 1], nums2[j - 1]);
			if ((m + n) & 1) 
				return num1;
			
			int num2;
			if (i == m) 
				num2 = nums2[j];
			else if 
				(j == n) num2 = nums1[i];
			else 
				num2 = min(nums1[i], nums2[j]);			
			return (num1 + num2) / 2.0;
    }
};

