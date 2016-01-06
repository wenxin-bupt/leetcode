/**
	Problem: ZigZag Conversion
	Link:https://leetcode.com/problems/zigzag-conversion/
	Time complexity:O(n)
	Space complexity:O(n)
	Runtime:16ms
**/


//runtime 16ms
class Solution{
	public:
    string convert(string s, int numRows) {
		if(numRows<2)
			return s;
        //nums of char each box contains
		int k = numRows*2 - 2;
		int length = s.size();
		//向上取整
		int numBoxes = (length + k -1) / k; 
        string b;
		b.resize(length);
		int mark = 0;
		for(int i=0; i<numRows; i++){
			for(int j=0; j<numBoxes;j++){
				if(j*k+i<length)
					b[mark++]=s[j*k+i];
				if(i!=0&&i!=numRows-1&&k-i+k*j<length)
					b[mark++]=s[k-i+k*j];
			}
		}
		return b;
    }
};


//runtime 172ms farm animals
/*
class Solution {
public:
    string convert(string s, int numRows) {
		if(numRows<2)
			return s;
        //nums of char each box contains
		int k = numRows*2 - 2;
		int length = s.size();
		//向上取整
		int numBoxes = (length + k -1) / k; 
		vector<vector<char>> box;
		box.resize(numRows, vector<char>(numBoxes*(numRows-1),0));

		int mark = 0;
		for(int i=0; i<numBoxes; i++){
			for(int j=i*k; j<length&&j<(i+1)*k;){
				//竖行1
				for(int p=0; j<length&&p<numRows; p++){
					box[p][i*(numRows-1)]=s[j++];
				}
				//对角线
				for(int q=numRows-2; j<length&&q>0; q--){
					box[q][numRows-1-q+i*(numRows-1)]=s[j++];
				}
			}
		}
		string b;
		for(int m=0; m<numRows; m++){
			for(int n=0; n<(numRows-1)*numBoxes; n++){
				if(box[m][n]!=0)
					b.push_back(box[m][n]);
			}
		}
		return b;
    }
};
*/