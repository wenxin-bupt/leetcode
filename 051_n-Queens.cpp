/**
	Problem: Wildcard Matching
	Link:https://leetcode.com/problems/wildcard-matching/
	Reference:
**/

/**
	The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
	Given an integer n, return all distinct solutions to the n-queens puzzle.
	Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
	For example,
	There exist two distinct solutions to the 4-queens puzzle:
	[
	 [".Q..",  // Solution 1
	  "...Q",
	  "Q...",
	  "..Q."],

	 ["..Q.",  // Solution 2
	  "Q...",
	  "...Q",
	  ".Q.."]
	]
**/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
		
		vector<vector<int>> res;
        vector<bool> colMarker(n,true);
		vector<bool> diagMarker1(n+n-1,true);
		vector<bool> diagMarker2(n+n-1,true);
		vector<int> subRes;
		cur(res, colMarker, diagMarker1, diagMarker2, subRes, n, 0);
		vector<vector<string>> ret;
		for(int k=0; k<res.size(); k++){
			string cache(n, '.');
			vector<string> subMatrix(n,cache);
			for(int i=0; i<n; i++){
				subMatrix[i][res[k][i]] = 'Q';
			}
			ret.push_back(subMatrix);
		}
		return ret;
    }
private:
	void cur(vector<vector<int>> &res, vector<bool> colMarker, vector<bool> diagMarker1, vector<bool> diagMarker2, vector<int> subRes, int n, int i){	
		if(i == n){
			res.push_back(subRes);
			return;
		}
		for(int j=0; j<n; j++){
			if(colMarker[j]&&diagMarker1[i+j]&&diagMarker2[i-j+n-1]){
				colMarker[j] = false;
				diagMarker1[i+j] = false;
				diagMarker2[i-j+n-1] = false;
				subRes.push_back(j);
				cur(res, colMarker, diagMarker1, diagMarker2, subRes, n, i+1);
				subRes.pop_back();
				colMarker[j] = true;
				diagMarker1[i+j] = true;	
				diagMarker2[i-j+n-1] = true;
			}
		}
		return;
	}
};