
//runtime 88ms solution
//ugly but somehow works!
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
		if(x>=0&&x<10)
			return true;
		int i=9, k=0;
		while(!(x/pow(i)))
			i--;
		while(((x/pow(i))%10)==((x/pow(k))%10)&&i>k){
			i--;
			k++;
		}
		if(!(i>k))
			return true;
		return false;
    }
	int pow(int a){
		switch(a){
			case 0:
				return 1;
				break;
			case 1:
				return 10;
				break;
			case 2:
				return 100;
				break;
			case 3:
				return 1000;
				break;
			case 4:
				return 10000;
				break;
			case 5:
				return 100000;
				break;
			case 6:
				return 1000000;
				break;
			case 7:
				return 10000000;
				break;
			case 8:
				return 100000000;
				break;
			case 9:
				return 1000000000;
				break;
			default:
				return 1;
			}

	}
};