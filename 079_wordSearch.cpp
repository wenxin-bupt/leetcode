/**
	Problem:Word Search
	Link:https://leetcode.com/problems/word-search/
	Reference:https://leetcode.com/discuss/27445/my-19ms-accepted-c-code
**/

/**
	Given a 2D board and a word, find if the word exists in the grid.
	The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. 
	The same letter cell may not be used more than once.

	For example,
	Given board =
	[
	  ['A','B','C','E'],
	  ['S','F','C','S'],
	  ['A','D','E','E']
	]
	word = "ABCCED", -> returns true,
	word = "SEE",    -> returns true,
	word = "ABCB",   -> returns false.
**/

//19ms Solution
//[Recursive] 未使用栈 很精巧 
//Space complexity: O(4^n)
class Solution {
public:
	 bool exist(vector<vector<char>> &board, string word) {
		 m=board.size();
		 n=board[0].size();
		for(int x=0;x<m;x++)
			for(int y=0;y<n;y++)
			{
				if(isFound(board,word.c_str(),x,y))
					return true;
			}
		return false;
	}
private:
	int m;
	int n;
	bool isFound(vector<vector<char>> &board, const char* w, int x, int y)
	{
		if(x<0||y<0||x>=m||y>=n||board[x][y]=='\0'||*w!=board[x][y])
			return false;
		if(*(w+1)=='\0')
			return true;
		char t=board[x][y];
		board[x][y]='\0';
		if(isFound(board,w+1,x-1,y)||isFound(board,w+1,x+1,y)||isFound(board,w+1,x,y-1)||isFound(board,w+1,x,y+1))
			return true; 
		board[x][y]=t;
		return false;
	}
};

//My 68ms colution
//在使用一个新的matrix标记是否访问过和使用一个很长的固定数组作为栈的时候很难提升运行时间.
//Nonrecursive
//Space complexity: O(n^m)
//Time complexity: O(n^2)
/*
class Pos{
public:
	Pos(int a, int b);
	int i;
	int j;
};
Pos::Pos(int a=0, int b=0):i(a),j(b){};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
		int col = board[0].size();
		vector<bool> markRow(col, true);
		vector<vector<bool>> matrix(row,markRow);
		Pos headQ[200]; int headP = -1;
		Pos resQ[1000]; int resP = -1;
		
	    bool flag = true;
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				if(board[i][j]==word[0]){
					flag = false;
					headQ[++headP] = Pos(i,j);
				}
			}
		}
		if(flag)
			return false;
		
		bool sign = false;
		resQ[++resP] = headQ[headP]; 
		Pos visitP1;
		first(resQ[resP], visitP1, matrix);
		int visitP2 = 1;
		if(visitP2==word.size())
			return true;
		while(headP!=-1){
			if(sign){
				visitP1 = resQ[resP--];
				matrix[visitP1.i][visitP1.j] = true;
				visitP2--;
				if(resP==-1){
				    headP--;
					if(headP==-1)
						break;
					matrix[resQ[0].i][resQ[0].j] = true;
					resQ[++resP] = headQ[headP];
					first(resQ[resP], visitP1, matrix);
					sign = false;
					visitP2 = 1;
					continue;
				}
				if(!next(resQ[resP], visitP1, matrix)){
					sign = true;
				}else{
					sign = false;
				}
			}else{
			    if(board[visitP1.i][visitP1.j]==word[visitP2]){
					resQ[++resP] = visitP1;
					if(!first(resQ[resP], visitP1, matrix))
						sign = true;
					visitP2++;
					if(visitP2==word.size())
						return true;
				}else{
					if(!next(resQ[resP], visitP1, matrix)){
						sign = true;
					}
				}
			}
		}
		return false;
    }
	
private:
	bool first(Pos pivot, Pos &visitP, vector<vector<bool>> &matrix){
		if(matrix[pivot.i][pivot.j])
			matrix[pivot.i][pivot.j] = false;
		
		int row = matrix.size();
		int col = matrix[0].size();
		int i = pivot.i;
		int j = pivot.j;
		
		if(i-1>=0&&matrix[i-1][j]){
			visitP.i = i-1;
			visitP.j = j;
			matrix[i-1][j] = false;
			return true;
		}
		
		if(j+1<col&&matrix[i][j+1]){
			visitP.i = i;
			visitP.j = j+1;
			matrix[i][j+1] = false;
			return true;
		}
		
		if(i+1<row&&matrix[i+1][j]){
			visitP.i = i+1;
			visitP.j = j;
			matrix[i+1][j] = false;
			return true;
		}
		
		if(j-1>=0&&matrix[i][j-1]){
			visitP.i = i;
			visitP.j = j-1;
			matrix[i][j-1] = false;
			return true;
		}
		
		return false;
	}
	
	bool next(Pos pivot, Pos &visitP, vector<vector<bool>> &matrix){
		
		int row = matrix.size();
		int col = matrix[0].size();
		int i = pivot.i;
		int j = pivot.j;
		int mark;
		
		if(i-visitP.i==1){
			mark = 1;
		}else if(visitP.j-j==1){
			mark = 2;
		}else if(visitP.i-i==1){
			mark = 3;
		}else{
			mark = 4;
		}
		matrix[visitP.i][visitP.j] = true;
		switch(mark){
			case 1:
				if(j+1<col&&matrix[i][j+1]){
					visitP.i = i;
					visitP.j = j+1;
					matrix[i][j+1] = false;
					return true;
				}
			case 2:
				if(i+1<row&&matrix[i+1][j]){
					visitP.i = i+1;
					visitP.j = j;
					matrix[i+1][j] = false;
					return true;
				}
			case 3:
				if(j-1>=0&&matrix[i][j-1]){
					visitP.i = i;
					visitP.j = j-1;
					matrix[i][j-1] = false;
					return true;
				}
			case 4:
				return false;
		}
	}
	
};
*/
