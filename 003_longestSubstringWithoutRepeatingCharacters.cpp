//2016 1 4 

/**
	Problem: Longest Substring Without Repeating Characters
	Link:https://leetcode.com/problems/longest-substring-without-repeating-characters/
**/
/**
	Requirements:
	There are two sorted arrays nums1 and nums2 of size m and n respectively. 
	Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
**/


//submit version
class Solution {
public:
    
	int lengthOfLongestSubstring(string s) {
		int ifortest = 0;
		if(s.size()==0) return 0;
        vector<int> markArray(256,0);
		int p = 0, q = 0;
		int m = 1, k = 1;
		while(p<s.size()){
			fill(markArray.begin(),markArray.end(),0);
			markArray[s[p]] = 1;
			q = p + 1;
			k = 1;
			while(q<s.size()){
				if(markArray[s[q]]!=0){
					m = max(m, k);
					break;
				}
				markArray[s[q]] = 1;
				k++;
				q++;
				m = max(m, k);
			}
			p++;
		}
		return m;
    }


};




