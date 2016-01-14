/**
	Problem:Palindrome Partitioning
	Link:https://leetcode.com/problems/palindrome-partitioning/
	Time complexity:O(n^2)
	Space complexity:O(n^2)
**/

/**
	Given a string s, partition s such that every substring of the partition is a palindrome.
	Return all possible palindrome partitioning of s.
	For example, given s = "aab",
	Return
	[
		["aa","b"],
		["a","a","b"]
    ]
**/
//Runtime 20ms, beats 53.12%
//需要了解DP和其他简明的解法
class Solution {
public:
    vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> sep;
		string cache;
		for(int i = 0; i<s.size(); i++){
			cache = s[i];
			sep.push_back(cache);
		}
		res.push_back(sep);
		cur(sep,0, res);
		return res;
    }
	
private:
	void cur(vector<string> sep, int start, vector<vector<string>> &res ){
		string cache;
		vector<string> temp, reserve = sep;
		if(start > sep.size()-2)
			return;
		for(int i=start; i<reserve.size()-1; i++){
		    sep = reserve;
		    temp = reserve;
			//even mode
			if(sep[i]==sep[i+1]){
				cache = sep[i] + sep[i+1];
				sep.erase(sep.begin()+i,sep.begin()+i+2);
				sep.insert(sep.begin()+i, cache);
				res.push_back(sep);
				cur(sep,i,res);
			}
			//odd mode
			if(i>0&&temp[i-1]==temp[i+1]){
				cache = temp[i-1] +temp[i] + temp[i+1];
				temp.erase(temp.begin()+i-1, temp.begin()+i+2);
				temp.insert(temp.begin()+i-1,cache);
				res.push_back(temp);
				cur(temp, i-1, res);
			}
		}
		return;
	}
};