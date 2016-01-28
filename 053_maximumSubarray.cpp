/**
	Problem: Maximum Subarray
	Link:https://leetcode.com/problems/maximum-subarray/
	Reference:https://leetcode.com/discuss/11288/simplest-and-fastest-o-n-c-solution
**/

/**
	Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
	For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
	the contiguous subarray [4,−1,2,1] has the largest sum = 6.
**/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans=nums[0], i, j, sum=0;
        for(i=0;i<n;i++){
            sum+=nums[i];
            ans=max(sum,ans);
            sum=max(sum,0);
        }
        return ans;
    }
};