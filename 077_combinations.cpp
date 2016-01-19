/**
	Problem: Combinations
	Link:https://leetcode.com/problems/combinations/
	Reference:
**/

/**
	Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

	For example,
	If n = 4 and k = 2, a solution is:
	[
	  [2,4],
	  [3,4],
	  [2,3],
	  [1,2],
	  [1,3],
	  [1,4],
	]
**/

//16ms Recursive solution
//Space complexity: O(2^n)
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
		if(k==0){
			res.push_back({});
			return res;
		}
		if(n<k){
			return res;
		}
		if(k==1)
			for(int i=1; i<=n; i++){
				res.push_back({i});
			}
		else
			for(int i=1; i<=n; i++){
				cur(res,n,k,{i},i);
			}
		return res;	
    }
private:
	void cur(vector<vector<int>> &res, int n, int k, vector<int> elem, int tail){
		tail++;
		if(elem.size()+1==k)
			for(int i=tail; i<=n; i++){
				elem.push_back(i);
				res.push_back(elem);
				elem.pop_back();
			}
		else
			for(int i=tail; i<=n; i++){
				elem.push_back(i);
				cur(res,n,k,elem,i);
				elem.pop_back();
			}
		return;
	}
};


