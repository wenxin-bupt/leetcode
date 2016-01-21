/**
	Problem: Roman to Integer
	Link:https://leetcode.com/problems/roman-to-integer/
**/

/**
	Given a roman numeral, convert it to an integer.
	Input is guaranteed to be within the range from 1 to 3999.
**/

//使用hash map 或 switch 运行时间相同
//Runtime 60ms
class Solution {
public:
    int romanToInt(string s) {
		int res = 0;
		int n, m;	
		unordered_map<char, int> T = { { 'I' , 1 },
									   { 'V' , 5 },
									   { 'X' , 10 },
									   { 'L' , 50 },
									   { 'C' , 100 },
									   { 'D' , 500 },
									   { 'M' , 1000 } 
		};
		m = T[s[0]];
		for(int i=0; i<s.size(); i++){
			n = T[s[i]];
			if(n>m)
				res += n-2*m;
			else
				res += n;
			m = n;
		}
		return res;
    }
private:
	int getValue(char a){
		switch(a){
			case 'I':
				return 1;
			case 'V':
				return 5;
			case 'X':
				return 10;
			case 'L':
				return 50;
			case 'C':
				return 100;
			case 'D':
				return 500;
			case 'M':
				return 1000;
		}
	}
};


