/**
	Problem: N-Queens II
	Link:https://leetcode.com/problems/n-queens-ii/
	Reference:
**/

/**
	Follow up for N-Queens problem.
	Now, instead outputting board configurations, return the total number of distinct solutions.
**/

class Solution {
public:
    int totalNQueens(int n){
		
		vector<vector<int>> res;
        vector<bool> colMarker(n,true);
		vector<bool> diagMarker1(n+n-1,true);
		vector<bool> diagMarker2(n+n-1,true);
		cur(colMarker, diagMarker1, diagMarker2, n, 0, m);
		return m;
    }
private:
	void cur(vector<bool> colMarker, vector<bool> diagMarker1, vector<bool> diagMarker2, int n, int i, int &m){	
		if(i == n){
			m++;
			return;
		}
		for(int j=0; j<n; j++){
			if(colMarker[j]&&diagMarker1[i+j]&&diagMarker2[i-j+n-1]){
				colMarker[j] = false;
				diagMarker1[i+j] = false;
				diagMarker2[i-j+n-1] = false;
				cur(colMarker, diagMarker1, diagMarker2, n, i+1, m);
				colMarker[j] = true;
				diagMarker1[i+j] = true;	
				diagMarker2[i-j+n-1] = true;
			}
		}
		return;
	}
};