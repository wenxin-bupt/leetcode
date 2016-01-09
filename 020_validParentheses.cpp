/**
	Problem: Valid Parentheses
	Link:https://leetcode.com/problems/valid-parentheses/
**/
/**
	Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
	The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
**/
class Solution {
public:
    bool isValid(string s) {
        int length = s.size();
		int pointer = -1, i = 0;
		vector<char> stack;
		stack.resize(length);
		while(i<length){
			if(s[i]=='}'||s[i]==']'||s[i]==')'){
				if(pointer == -1)
					return false;
				switch(s[i]){
					case '}':
						if(stack[pointer]!='{')
							return false;
						break;
					case ']':
						if(stack[pointer]!='[')
							return false;
						break;
					case ')':
						if(stack[pointer]!='(')
							return false;
						break;
				}
				pointer--;
			}else if(s[i]=='{'||s[i]=='['||s[i]=='(')
				stack[++pointer]=s[i];
			i++;	
		}
		if(pointer>-1)
			return false;
		return true;
    }
};
