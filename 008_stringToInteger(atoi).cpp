//12 ms solution
//not enough
class Solution {
public:
    int myAtoi(string str) {
        long long y  = 0;
		int k = 0, p = 0;
		int length = str.size();
		while(str[p]==' ')
		    p++;
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