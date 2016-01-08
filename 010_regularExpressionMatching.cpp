//My 536 ms solution, beats 11.70%
//愚蠢也是一种天赋，谁说不是呢？
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