/**
	Problem: Letter Combinations of a Phone Number
	Link:https://leetcode.com/problems/letter-combinations-of-a-phone-number/
**/

/**
	Given a digit string, return all possible letter combinations that the number could represent.
	For example:
	Input:Digit string "23"
	Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
	Note:
	Although the above answer is in lexicographical order, your answer could be in any order you want.
**/

//hash map作为类成员可以提升运行时间
class Solution {
public:
    vector<string> letterCombinations(string digits) {
		vector<string> res;
		if(digits.size()==0)
			return res;
		string elem;
		cur(digits, res, elem, 0);
		return res;
    }
private:
	unordered_map<char, string> T = { 	{ '1' , "1" },
										{ '2' , "abc" },
										{ '3' , "def" },
										{ '4' , "ghi" },
										{ '5' , "jkl" },
										{ '6' , "mno" },
										{ '7' , "pqrs" },
										{ '8' , "tuv" },
										{ '9' , "wxyz" }, 
										{ '*' , "x" }, 
										{ '0' , " " },
										{ '#' , "#" }
									};
	void cur(const string digits, vector<string> &res, string elem, int pointer){
		if(pointer == digits.size()){
			res.push_back(elem);
			return;
		}
		string cache = T[digits[pointer]];
		for(int i=0, max=cache.size(); i<max; i++){
			cur(digits, res, elem+cache[i], pointer+1);
		}
		return;
	}
};


