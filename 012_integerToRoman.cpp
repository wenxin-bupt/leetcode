/**
	Problem: Integer to Roman
	Link:https://leetcode.com/problems/integer-to-roman/
**/

/**
	Given an integer, convert it to a roman numeral.
	Input is guaranteed to be within the range from 1 to 3999.
**/

//谢谢喵酱~
class Solution {
public:
    string intToRoman(int num) {
		string p[34] = {"", "M", "MM", "MMM",
		                "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
		                "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
		                "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
		return p[num/1000] + p[num%1000/100+4] + p[num%100/10+14] + p[num%10+24];
	}
};

	


