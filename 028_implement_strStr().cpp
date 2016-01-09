/**
	Problem: Implement strStr()
	Link:https://leetcode.com/problems/implement-strstr/
	Time complexity:O(N+M) (Using KMP)
	Space complexity:O(M)
	Runtime:4ms
**/

/**
	Implement strStr().
	Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
**/

//My solution
//4ms runtime
class Solution {
public:
    int strStr(string haystack, string needle) {
	int lengthH = haystack.size();
	int lengthN = needle.size();
	if(lengthN>lengthH)
		return -1;
	vector<int> next;
	next.resize(lengthN,-1);
	
	//Next array generating
	if(lengthN>1){
		int k;
		next[1]=0;
		for(int i=2; i<lengthN; i++){
			if(needle[i-1]==needle[next[i-1]])
				next[i] = next[i-1]+1;
			else{
				k = next[i-1];
				while(next[k]!=-1&&needle[k]!=needle[next[k]]){
					k = next[k];
				}
				next[i] = next[k];
				if(k==0)
				  next[i] = 0;
			}
		}
	}
	
	//匹配
	int p=0 ,q=0;
	while(p<lengthH&&q<lengthN){
		if(haystack[p]==needle[q]){
			p++;
			q++;
		}else if(next[q]==-1){
			p++;
		}else{
			q = next[q];
		}
	}
	if(q==lengthN)
		return p-lengthN;
	return -1;	
    }
};