/**
	Problem: Divide Two Integers
	Link:https://leetcode.com/problems/divide-two-integers/
	Reference:https://leetcode.com/discuss/38997/detailed-explained-8ms-c-solution
**/

/**
	Divide two integers without using multiplication, division and mod operator.
	If it is overflow, return MAX_INT.
**/
 
class Solution {
public:
    int divide(int dividend, int divisor) {
		if(divisor==0||(dividend==INT_MIN&&divisor==-1))
			return INT_MAX;
		int sign = ((dividend>0)^(divisor>0))? -1 : 1; 
		long long dvd = labs(dividend);
		long long dvs = labs(divisor);
		int res = 0;
		while(dvd>=dvs){
			long long temp = dvs, multiple = 1;
			while(dvd>=(temp<<1)){
				temp <<= 1;
				multiple <<= 1;
			}
			res += multiple;
			dvd -= temp;
		}
		return sign == 1 ? res : -res;
    }
};


