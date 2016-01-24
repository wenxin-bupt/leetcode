/**
	Problem: Multiply Strings
	Link:https://leetcode.com/problems/multiply-strings/
	Reference:https://leetcode.com/discuss/26602/brief-c-solution-using-only-strings-and-without-reversal
**/

/**
	Given two numbers represented as strings, return multiplication of the numbers as a string.
	Note: The numbers can be arbitrarily large and are non-negative.
**/

class Solution {
public:
   string multiply(string num1, string num2) {
		string sum(num1.size() + num2.size(), '0');
		for (int i = num1.size() - 1; 0 <= i; --i) {
			int carry = 0;
			for (int j = num2.size() - 1; 0 <= j; --j) {
				int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
				sum[i + j + 1] = tmp % 10 + '0';
				carry = tmp / 10;
			}
			sum[i] += carry;
		}
		size_t startpos = sum.find_first_not_of("0");
		if (string::npos != startpos) {
			return sum.substr(startpos);
		}
		return "0";
	}
};

/*
//权当展示原理吧，如此愚蠢....
class Solution {
public:
    string multiply(string num1, string num2) {
		string res;
		if((num1.size()==1&&num1[0]=='0')&&(num2.size()==1&&num2[0]=='0'))
			return "0";
		for(int q = num1.size() - 1; q>=0; q--){
			string cache;
			multi(cache, num1, num2, q);
			addStr(res, cache, num1.size() - 1 - q);
		}
		return res;
    }
private:
	void multi(string &multiRes, string &num1, string &num2, int q){
		int p = num2.size()-1;
		int a = num1[q] - '0', b, c, mark = 0, drop = 0;
		char ele;
		for(;p>=0;p--){
			b = num2[p] - '0';
			c = a * b + mark;
			mark = c / 10;
			drop = c % 10;
			ele = '0' + drop;
			multiRes = ele + multiRes;
		}
		if(mark > 0){
			ele = '0' + mark;
			multiRes = ele + multiRes;
		}	
	}
	
	void addStr(string &num1, string &num2, int m){
		int p = num2.size() - 1;
		int q = num1.size() - 1 - m;
		int a, b, c, mark = 0, drop = 0;
		char ele;
		while(q>=0&&p>=0){
			a = num1[q] - '0';
			b = num2[p] - '0';
			c = a + b + mark;
			mark = c / 10;
			drop = c % 10;
			ele = '0' + drop;
			num1[q] = ele;
			q--;
			p--;
		}
		while(q>=0){
			a = num1[q] - '0';
			c = a + mark;
			mark = c / 10;
			drop = c % 10;
			ele = '0' + drop;
			num1[q] = ele;
			q--;
		}
		while(p>=0){
			b = num2[p] - '0';
			c = b + mark;
			mark = c / 10;
			drop = c % 10;
			ele = '0' + drop;
			num1 = ele + num1;
			p--;
		}
		if(mark > 0){
			ele = '0' + mark;
			num1 = ele + num1;
		}	
	}
};
*/

