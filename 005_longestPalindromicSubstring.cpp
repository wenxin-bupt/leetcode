//runtime 64ms 
class Solution {
public:
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
};