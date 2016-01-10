/**
	Problem:Valid Number
	Link:https://leetcode.com/problems/valid-number/
	Time complexity:O(n) 
	Runtime:8ms
**/

/**
	Validate if a given string is numeric.

	Some examples:
	"0" => true
	" 0.1 " => true
	"abc" => false
	"1 a" => false
	"2e10" => true
	
	Note: It is intended for the problem statement to be ambiguous. 
		  You should gather all requirements up front before implementing one.
**/


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
//无比臃肿....其中signFlag是没有必要的...但又想不到好的办法拿掉
//运行时间还可以.
class Solution {
public:
    bool isNumber(string s) {
		if(s.size()==0)
			return false;
        int head=0, tail=s.size()-1;
		int length = s.size();
		
		while(head<length&&s[head]==' ')
			head++;
		while(tail>=0&&s[tail]==' ')
			tail--;
		
		if(head>tail)
			return false;
		
		tail++;
		
		//特殊情况处理
		if(tail-head==1&&!(s[head]>='0'&&s[head]<='9'))
			return false;
		
		bool signFlag = true, dotFlag = true, eFlag = true;
		
		if(s[head]=='+'||s[head]=='-')
			signFlag = false;
		else if(s[head]=='.'){
			dotFlag = false;
			signFlag = false;
		}else if(s[head]>='0'&&s[head]<='9')
			signFlag = false;
		else 
			return false;
		
		int pointer = head+1;
		//特殊情况处理
		if(tail-head==2&&(s[head]=='+'||s[head]=='-')&&s[pointer]=='.')
		    return false;
		
		while(pointer<tail){
			if(s[pointer]>='0'&&s[pointer]<='9'){
				pointer++;
			}else if(s[pointer]=='.'){
				if(dotFlag){
					dotFlag = false;
					pointer++;
				}else
					return false;
			}else if(s[pointer]=='e'){
				
				if(eFlag){
					eFlag=false;
					dotFlag = false;
					
					//处理e之前部分的特殊情况
					if(s[pointer-1]=='+'||s[pointer-1]=='-')
						return false;
					else if(pointer-2==head&&(s[pointer-2]=='+'||s[pointer-2]=='-')&&s[pointer-1]=='.')
						return false;
					else if(pointer-1==head&&s[pointer-1]=='.')
						return false;
					else
						pointer++;
					
					//处理e之后部分的特殊情况
					if(tail==pointer||(tail-pointer==1&&!(s[pointer]>='0'&&s[pointer]<='9')))
						return false;
					
					if(s[pointer]=='+'||s[pointer]=='-')
						signFlag = false;
					else if(s[pointer]>='0'&&s[pointer]<='9')
						signFlag = false;
					else 
						return false;
					
				}else
					return false;				
				pointer++;
			
			}else
				return false;
		}
		return true;
    }
};