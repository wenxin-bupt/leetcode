/**
	Problem:Add Binary
	Link:https://leetcode.com/problems/add-binary/
	Time complexity:O(n)
	Space complexity:O(n)
**/

/**
	Given two binary strings, return their sum (also a binary string).
	For example,
	a = "11"
	b = "1"
	Return "100".
**/

//Runtime 4ms
class Solution {
public:
    string addBinary(string a, string b) {
        bool sign = false;
		string res;
		if(a.size()==0)
			return b;
		if(b.size()==0)
			return a;
		int p=a.size()-1, q=b.size()-1;
		while(p>=0&&q>=0){
			if(a[p]=='0'){
				if(b[q]=='0'){
					if(sign){
						res = '1' + res;
						sign = false;
					}else
						res = '0' + res;
				}else{
					if(sign)
						res = '0' + res;
					else{
						res = '1' + res;
						sign = false;
					}
				}
				p--; q--;
			}else{
				if(b[q]=='0'){
					if(sign)
						res = '0' + res;
					else{
						res = '1' + res;
						sign = false;
					}
				}else{
					if(sign)
						res = '1' + res;
					else{
						res = '0' + res;
						sign = true;
					}
				}
				p--; q--;
			}
		}
		
		while(p>=0){
			if(a[p]=='0'){
				if(sign)
					res = '1' + res;
				else
					res = '0' + res;
				sign =false;
				p--;
			}else{
				if(sign)
					res = '0' + res;
				else{
					res = '1' + res;
					sign = false;
				}
				p--;
			}
		}
		
		while(q>=0){
			if(b[q]=='0'){
				if(sign)
					res = '1' + res;
				else
					res = '0' + res;
				sign =false;
				q--;
			}else{
				if(sign)
					res = '0' + res;
				else{
					res = '1' + res;
					sign = false;
				}
				q--;
			}
		}
		if(sign)
		    res = '1' + res;
		return res;
    }
};