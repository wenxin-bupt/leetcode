/**
	Problem: Sqrt(x)
	Link:https://leetcode.com/problems/sqrtx/
	Reference:http://www.cnblogs.com/bigrabbit/archive/2012/09/25/2702174.html
**/

/**
	Implement int sqrt(int x).
	Compute and return the square root of x.
**/

//牛顿迭代求根法
//在讨论区有另一种使用二分查找求根的方法，具有相同的运行时间
class Solution {
public:
    int mySqrt(int x) {
		double g0,g1;   
		if(x==0||x==1)   
			return x;  
		if()
		g0=x/2;   
		g1=(g0+x/g0)/2;   
		while(abs(g1-g0)>=1)   
		{   
			g0=g1;   
			g1=(g0+(x/g0))/2;   
		}   
		return (int)g1;   
	} 
};


