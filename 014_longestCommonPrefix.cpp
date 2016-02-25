/**
	Problem:Longest Common Prefix
	Link:https://leetcode.com/problems/longest-common-prefix/
	Reference:https://leetcode.com/discuss/50989/accepted-c-6-lines-4ms
**/

/**
	Write a function to find the longest common prefix string amongst an array of strings.
**/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for(int idx=0; strs.size()>0; prefix+=strs[0][idx], idx++)
            for(int i=0; i<strs.size(); i++)
                if(idx >= strs[i].size() ||(i > 0 && strs[i][idx] != strs[i-1][idx]))
                    return prefix;
    }
};