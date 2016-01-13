/**
	Problem:Valid Palindrome
	Link:https://leetcode.com/problems/valid-palindrome/
	Reference:https://leetcode.com/discuss/17398/heres-a-clean-c-solution
**/

/**
	Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
	For example,
	"A man, a plan, a canal: Panama" is a palindrome.
	"race a car" is not a palindrome.
**/

//12ms solution.
class Solution {
public:
    bool isPalindrome(string s) {
		for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
			while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
			while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
			if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
		}
		return true;
	}
}

//16ms solution
/*
class Solution {
public:
    bool isPalindrome(string s) {
        int length = s.size();
		int p = 0, q = length-1;
		while(p<length&&!((s[p]>='0'&&s[p]<='9')||(s[p]>='a'&&s[p]<='z')||(s[p]>='A'&&s[p]<='Z')))
			p++;
		if(p==length)
			return true;
		while(q>=0&&!((s[q]>='0'&&s[q]<='9')||(s[q]>='a'&&s[q]<='z')||(s[q]>='A'&&s[q]<='Z')))
			q--;
		while(q>=p){
			if(s[p]>='0'&&s[p]<='9'){
				if(s[p]!=s[q])
					return false;
			}else if(s[p]>='a'&&s[p]<='z'){
				if(s[p]!=s[q]&&s[p]-'a'!=s[q]-'A')
					return false;
			}else{
				if(s[p]!=s[q]&&s[p]-'A'!=s[q]-'a')
					return false;
			}
			p++;
			q--;
			while(p<length&&!((s[p]>='0'&&s[p]<='9')||(s[p]>='a'&&s[p]<='z')||(s[p]>='A'&&s[p]<='Z')))
				p++;
			while(q>=0&&!((s[q]>='0'&&s[q]<='9')||(s[q]>='a'&&s[q]<='z')||(s[q]>='A'&&s[q]<='Z')))
				q--;
		}
		return true;
    }
};
*/