/**
	Problem: Combination Sum
	Link:https://leetcode.com/problems/combination-sum/
**/

/**
	Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
	The same repeated number may be chosen from C unlimited number of times.
	Note:
	All numbers (including target) will be positive integers.
	Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
	The solution set must not contain duplicate combinations.
	For example, given candidate set 2,3,6,7 and target 7, 
	A solution set is: 
	[7] 
	[2, 2, 3] 
**/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
        vector<int> mark(candidates.size(), 0);
		vector<vector<int>> res;
		cur(res, candidates, mark, target, 0, 0);
		return res;
    }
	
private:
	void cur(vector<vector<int>> &res, const vector<int> &candidates, vector<int> mark, int target, int count, int p){
		if(p==candidates.size())
			return;
		int gap = target - count;
		if(candidates[p]>gap)
			return;
		int n = gap / candidates[p];
		mark[p] = n;
		if(gap%candidates[p]==0){
			vector<int> cache;
			for(int i=0; i<=p; i++)
				for(int j=0; j<mark[i]; j++)
					cache.push_back(candidates[i]);
			res.push_back(cache);
		}
		for(int k=n-1; k>=0; k--){
			mark[p] = k;
			cur(res, candidates, mark, target, count+k*candidates[p], p+1);
		}
	}
};



