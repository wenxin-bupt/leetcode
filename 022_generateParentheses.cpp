/**
	Problem: Generate Parentheses
	Link:https://leetcode.com/problems/generate-parentheses/
**/

/**
	Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
	For example, given n = 3, a solution set is:
	"((()))", "(()())", "(())()", "()(())", "()()()"
**/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> vec;
		string str;
		cur(vec, str, n, n, 0);
		return vec;
    }
private:
	void cur(vector<string> &vec, string str, int a, int b, int count){
		if(a==0&&b==0){
			vec.push_back(str);
			return;
		}
		if(a>0){
			string c1 = str + '(';
			cur(vec, c1, a-1, b, count+1);
		}
		if(b>0&&count>0){
			string c2 = str + ')';
			cur(vec, c2, a, b-1, count-1);
		}
		return;
	}
};



