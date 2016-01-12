/**
	Problem:Climbing Stairs
	Link:https://leetcode.com/problems/climbing-stairs/
	Time complexity:O(n) 
**/

/**
	You are climbing a stair case. It takes n steps to reach to the top.
	Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
**/


//斐波那契数列 动态规划
//什么是动态规划= =
class Solution {
public:
    int climbStairs(int n) {
		if(n==0)
			return 0;
		int j = 1, k = 1;
		int res = 1;
		for(int i=0; i<n-1; i++){
			res = k + j;
			k = j;
			j = res;
		}
		return res;
    }
};
