/**
	Problem: Subsets
	Link:https://leetcode.com/problems/subsets/
	Reference:https://leetcode.com/discuss/9213/my-solution-using-bit-manipulation
**/

/**
	Given a set of distinct integers, nums, return all possible subsets.
	
	Note:
	Elements in a subset must be in non-descending order.
	The solution set must not contain duplicate subsets.
	For example,
	If nums = [1,2,3], a solution is:
	[
	  [3],
	  [1],
	  [2],
	  [1,2,3],
	  [1,3],
	  [2,3],
	  [1,2],
	  []
	]
**/

//Beautiful solution!!!!
//Bit manipulation
//Space complexity: O(2^n)
//Time complexity: O(n*2^n)
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort (S.begin(), S.end());
        int elem_num = S.size();
        int subset_num = pow (2, elem_num);
        vector<vector<int> > subset_set (subset_num, vector<int>());
        for (int i = 0; i < elem_num; i++)
            for (int j = 0; j < subset_num; j++)
                if ((j >> i) & 1)
                    subset_set[j].push_back (S[i]);
        return subset_set;
    }
};

//My 8ms Recursive solution
//Space complexity: O(2^n)
/*
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(),nums.end());
		if(nums.size()==0){
			res.push_back(nums);
			return res;
		}
		res.push_back({});
		for(int i=0; i<nums.size(); i++){
			res.push_back({nums[i]});
			cur(res,nums,{nums[i]},i);
		}
		return res;
    }
private:
	void cur(vector<vector<int>> &res, const vector<int> &nums, vector<int> elem, int tail){
		tail++;
		vector<int> cache = elem;
		while(tail<nums.size()){
			elem = cache;
			elem.push_back(nums[tail]);
			res.push_back(elem);
			cur(res, nums, elem, tail);
			tail++;
		}
		return;
	}
};
*/
