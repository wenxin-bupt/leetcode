/**
	Problem: Regular Expression Matching
	Link:https://leetcode.com/problems/regular-expression-matching/
	Reference:https://leetcode.com/discuss/18970/concise-recursive-and-dp-solutions-with-full-explanation-in
	Runtime:72ms
**/
/**
	'.' Matches any single character.
	'*' Matches zero or more of the preceding element.

	The matching should cover the entire input string (not partial).

	The function prototype should be:
	bool isMatch(const char *s, const char *p)

	Some examples:
	isMatch("aa","a") → false
	isMatch("aa","aa") → true
	isMatch("aaa","aa") → false
	isMatch("aa", "a*") → true
	isMatch("aa", ".*") → true
	isMatch("ab", ".*") → true
	isMatch("aab", "c*a*b") → true
**/

/*
//The recursive concise solution
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())    return s.empty();
 
        if ('*' == p[1])
            // x* matches empty string or at least one character: x* -> xx*
            // *s is to ensure s is non-empty
            return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
        else
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
    }
};
*/

//DP solution based on the idea above
//16ms runtime!
class Solution {
public:
    bool isMatch(string s, string p) {
        /**
         * f[i][j]: if s[0..i-1] matches p[0..j-1]
         * if p[j - 1] != '*'
         *      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
         * if p[j - 1] == '*', denote p[j - 2] with x
         *      f[i][j] is true if any of the following is true
         *      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
         *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
         * '.' matches any single character
         */
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
 
        f[0][0] = true;
        for (int i = 1; i <= m; i++)
            f[i][0] = false;
        // p[0.., j - 3, j - 2, j - 1] matches empty iff p[j - 1] is '*' and p[0..j - 3] matches empty
        for (int j = 1; j <= n; j++)
            f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];
 
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] != '*')
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
                else
                    // p[0] cannot be '*' so no need to check "j > 1" here
                    f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];
 
        return f[m][n];
    }
};

//My 536 ms solution, beats 11.70%
/*
class Solution {
public:
    bool isMatch(string s, string p) {
        int pointer = 0;
		int fork = 0;
		int lengthS = s.size(), lengthP = p.size();
		string subS;
		string subP;
		while(pointer<lengthS&&fork<lengthP){
			if(fork<lengthP-1&&p[fork+1]=='*'){
				if(pointer<lengthS&&(p[fork]=='.'||s[pointer]==p[fork])){
					subS = s.substr(pointer+1);
					subP = p.substr(fork);
					if(isMatch(subS,subP))
						return true;
				    fork++;
				    fork++;
				}else{
				    fork++;
				    fork++;
				}
			}else if(p[fork]=='.'||p[fork]==s[pointer]){
				pointer++;
				fork++;
			} else if(s[pointer]!='.'&&s[pointer]!=p[fork])
				return false;
		}
		if(pointer==lengthS)
		    while(fork<lengthP-1&&p[fork+1]=='*')
		        fork+=2;
		        
		if(fork==lengthP&&pointer==lengthS)
			return true;
		else 
			return false;
	}
};
*/