/**
	Problem:Set Matrix Zeroes
	Link:https://leetcode.com/problems/set-matrix-zeroes/
	Reference:https://leetcode.com/discuss/15997/any-shortest-o-1-space-solution
	Time complexity:O(m*n)
	Space complexity:O(1)
**/

/**
	Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
**/

//Great idea.
//Concise and beautiful.
//使用Row0和Col0来存储行列情况.对于链接中的解法做了一点改进，减少了最后输出时的比较次数.
class Solution {
public:
   void setZeroes(vector<vector<int> > &matrix) {
		int row = matrix.size();
		if(row==0)
			return;
		int col = matrix[0].size();
		int col0 = 1; //For marking col0 as matrix[0][0] is for row0.
		
		for(int i=0; i<row; i++){
			if(matrix[i][0]==0)
				col0 = 0;
			for(int j=1; j<col; j++){
				if(matrix[i][j]==0){
					matrix[0][j] = 0; 
					matrix[i][0] = 0;
				}
			}
		}
		
		for(int i=row-1; i>=0; i--){
			if(matrix[i][0]==0)
				for(int j=1; j<col; j++)
					matrix[i][j] = 0;
			else{
				if(col0==0)
					matrix[i][0] == 0;
				for(int j=1; j<col; j++){
					if(matrix[0][j]==0)
						matrix[i][j] = 0;
					
				}
			}
		}
		return;
	}
};


//In fact it's an O(1) solution and it beats 63.11% of c++ submissions. LOL
//题目提供的测试矩阵始终小于200*200
//rowMarker[200]={false} 并不会使整个数组都置false，只会给下标为0的置false. 但是leetcode的编译器会把后面的值都置false作为默认初始化...
/*
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		bool rowMarker[200] = {false};
		bool colMarker[200] = {false};
		
		int row = matrix.size();
		if(row == 0)
			return;
		int col = matrix[0].size();
		for(int i=0; i<row; i++)
			for(int j=0; j<col; j++){
				if(matrix[i][j]==0){
					rowMarker[i] = true;
					colMarker[j] = true;
				}
			}

		for(int i=0; i<row; i++){
			if(rowMarker[i])
				for(int j=0; j<col; j++)
					matrix[i][j] = 0;
			else
				for(int j=0; j<col; j++){
					if(colMarker[j])
						matrix[i][j] = 0;
					
				}
		}
		return;
    }
};
*/