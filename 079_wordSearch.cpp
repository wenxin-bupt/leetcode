/**
	Problem: Word Search
**/
//My 88ms colution
class Pos{
public:
	Pos(int a, int b);
	int i;
	int j;
}
Pos::Pos(int a=0, int b=0):i(a),j(b){}

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
		int col = board[0].size();
		vector<bool> markRow(col, true);
		vector<vector<bool>> matrix(row,markRow);
		Pos headQ[100]; int headP = -1;
		Pos resQ[100]; int resP = -1;
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
			cout<<board[visitP1.i][visitP1.j];
			if(sign){
				visitP1 = resQ[resP--];
				matrix[visitP1.i][visitP1.j] = true;
				visitP2--;
				if(resP==-1){
					headP--;
					if(headP==-1)
						break;
					resQ[++resP] = headQ[headP];
					reFresh(matrix, markRow);
					first(resQ[resP], visitP1, matrix);
					visitP2 = 1;
					sign = false;
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
	
	void reFresh(vector<vector<bool>> &matrix, vector<bool> rowEle){
		for(int i=0; i<matrix.size(); i++){
			matrix[i].swap(rowEle);
		}
		return;
	}
};