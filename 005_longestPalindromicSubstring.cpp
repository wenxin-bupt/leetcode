//2016 1 6 11:51

/**
	Problem: Longest Palindromic Substring
	Link:https://leetcode.com/problems/longest-palindromic-substring/
	Reference:https://leetcode.com/discuss/40559/accepted-4ms-c-solution
	Time complexity:O(n^2)
	Space complexity:O(1)
	Runtime:4ms
**/
/**
	Requirements:
	Given a string S, find the longest palindromic substring in S. 
	You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
**/

class Solution {
public:

	#define SOLUTION_1
	
	#ifdef SOLUTION_1
	
//4 ms runtime solution
//Beautiful!!!
    std::string longestPalindrome(std::string s) {
        if (s.size() < 2)
            return s;
        int len = s.size(), max_left = 0, max_len = 1, left, right;
        for (int start = 0; start < len && len - start > max_len / 2;) {
            left = right = start;
//下面循环可以统一子数组的长度为奇偶的两种情况，偶数子串一定存在重复字符
            while (right < len - 1 && s[right + 1] == s[right])
                ++right;
            start = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right;
                --left;
            }
            if (max_len < right - left + 1) {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(max_left, max_len);
    }

	#else
	
//My solution
//Need to search in both even way and odd way 
//Runtime 64ms
//Time Complexity: O(n^2);
//Yinsengyijingrucijiannan~ 

    string longestPalindrome(string s) {
        int max = 1, front =  0, end = 0;
		int l = s.length();
		if(l <= 0)
			return s;
		int p = 1, m = 1;
		int f,e,k;
		while(p < l){
			//in even way
			f = p - 1;
			e = p;
			k = 1;
			while(f>=0&&e<l&&s[f]==s[e]){
				m = k<<1;
				if(m>max){
					front = f;
					end = e;
					max = m;
				}
				f--;
				e++;
				k++;
			}
			//in odd way
			f = p - 1;
			e = p + 1;
			k = 1;
			while(f>=0&&e<l&&s[f]==s[e]){
				m = k<<1 + 1;
				if(m>max){
					front = f;
					end = e;
					max = m;
				}
				f--;
				e++;
				k++;
			}
			p++;
		}
		return s.substr(front,end-front+1);
		
    }
	
	#endif
};