/**
	Problem: Reverse Integer
	Link:https://leetcode.com/problems/reverse-integer/
	Time complexity:O(1)
	Space complexity:O(1)
	Runtime:8ms
**/
/**
	Requirements:
	Reverse digits of an integer.
	Example1: x = 123, return 321
	Example2: x = -123, return -321
	If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
	Did you notice that the reversed integer might overflow? 
	Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
	For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
**/
//8ms solution
//运行时间看运气 :P
class Solution {
public:
    int reverse(int x) {
		int xMax = 2147483647;
		int xMin = -2147483648;
		vector<int> xStack(10,0);
		int m  = x;
		for(int i = 9; i>=0; i--){
			xStack[i] = x / pow(10,i);
			x -= pow(10,i) * xStack[i];
		}
		int p=9;
		double mark = 0;
		while(xStack[p]==0)
			p--;
		int k = p;
		while(p>=0){
			mark += xStack[p]*pow(10,k-p);
			p--;
		}
		if(mark>=xMin&&mark<=xMax)
			return (int)mark;
		else
			return 0;
    }
};