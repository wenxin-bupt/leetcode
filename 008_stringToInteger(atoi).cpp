/**
	Problem: String to Integer (atoi)
	Link:https://leetcode.com/problems/string-to-integer-atoi/
	Reference:https://leetcode.com/discuss/68729/8-line-c-concise-solution
	Time complexity:O(1)
	Space complexity:O(1)
	Runtime:8ms
**/
/**
	Requirements:
	Implement atoi to convert a string to an integer.
	etc.
**/

//8ms solution
//Beautiful!!
class Solution {
public:
	int myAtoi(string str) {
		int ret = 0, sign = 1, i = str.find_first_not_of(' '), base = INT_MAX / 10;
		if (str[i] == '+' || str[i] == '-') sign = str[i++] == '+' ?: -1;
		while (isdigit(str[i])) {
			if (ret > base || (ret == base && str[i] - '0' > 7)) 
				return sign > 0 ? INT_MAX : INT_MIN;
			ret = 10 * ret + (str[i++] - '0');
		}
		return sign * ret;
	}
};


//8 ms solution
//not concise enough 
/*
class Solution {
public:
    int myAtoi(string str) {
        long long y  = 0;
		int k = 0, p = 0;
		int length = str.size();
		//the key to improve runtime is to use this instead of while
		p = str.find_first_not_of(' ');
		if(str[p] == '-'){
			k = 1;
			p++;
		}else if(str[p] == '+'){
			p++;
		}
		if(!(str[p]>='0'&&str[p]<='9')){
		    return 0;
		}
		while(str[p]=='0')
		    p++;
		int m=0;
//虽然考虑到了在while中减少比较，但是也增加了新的m变量
//同时y会溢出，并不如上面的方法好
		while(p<length&&str[p]!='.'&&str[p]>='0'&&str[p]<='9'){
			y = y*10 + (str[p] - '0');
			p++;
			m++;
		}
		if(k)
			y = 0 -y;
		if(m>10&&!k) 
		    return INT_MAX;
	    if(m>10&&k)
	        return INT_MIN;
	    if(y > INT_MAX) 
		    return INT_MAX;
	    if(y < INT_MIN)
	        return INT_MIN;		    
	    return y;
	}
};
*/