/**
	Problem: Pow(x, n)
	Link:https://leetcode.com/problems/powx-n/
	Reference:https://leetcode.com/discuss/43818/non-recursive-c-log-n-solution
	Time complexity:O(LogN) 
	Space complexity:O(1)
	Runtime:4ms
**/

/**
	Implement pow(x, n).
**/

//Non-recursive C++ log(n) solution
//Beautiful and concise!
//特别注意INT_MIN在转换为-n时的溢出问题
//关于1LL 2LL http://stackoverflow.com/questions/16248221/what-is-1ll-or-2ll-in-c-and-c
class Solution {
public:
    double myPow(double x, int n) {
		double sum = 1;
		long long p;
		if(n<0){
			x = 1/x;
			p = (-1LL)*n;
		}else{
			p = n;
		}	
		while(p){
			if(p&1)
				sum*=x;
			x*=x;
			p>>=1;
		}
		return sum;
    }
};

//My solution
//20ms runtime, beats 1.5%;
//需要二分查找来大幅缩减比较数量 = =
//对于double的内建机制，并不需要用户去担心溢出问题。 
/*
class Solution {
public:
    double myPow(double x, int n) {
		double sum = 1.0;
		if(x==1.0)
			return sum;
		if(x==-1.0){
			return n%2==0?sum:-1.0; 
		}
		if(n==0)
			return sum;	
		double threshold;
		bool flagX = false, flagN =false;
		if(x<0){
			flagX = true;
			x = -x;
		}
		if(n<0){
			flagN = true;
			n = -n;
		}
		if(x>1.0){
			threshold = numeric_limits<double>::max()/x;
			for(int i=0; i<n; i++){
				if(sum<=threshold){
					sum*=x;
				}else{
					sum = numeric_limits<double>::max();
					break;
				}
			}
		}else{
			for(int i=0; i<n; i++){
				sum*=x;
				if(sum==0.0)
					return 0.0;
			}
		}
		
		if(!flagX&&!flagN)
			return sum;
		else if(!flagX&&flagN){
			return 1.0/sum;
		}else if(flagX&&!flagN){
			if(n%2==0)
				return sum;
			else
				return -sum;
		}else{
			if(n%2==0)
				return 1.0/sum;
			else
				return -1.0/sum;
		}
    }
};
*/