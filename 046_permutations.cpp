/**
	Problem: Permutations
	Link:https://leetcode.com/problems/permutations/
	Reference:https://leetcode.com/discuss/18212/my-elegant-recursive-c-solution-with-inline-explanation
**/

/**
	Given a collection of distinct numbers, return all possible permutations.
	For example,
	[1,2,3] have the following permutations:
	[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
**/

//想到一种不使用递归的，即逐渐增加节点，但是效率并不高。

//Runtime 16ms solution.
//另一种思路，使用交换来进行，效果很好
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;

        permuteRecursive(num, 0, result);
        return result;
    }
    void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)    {
        if (begin >= num.size()) {
            result.push_back(num);
            return;
        }
        for (int i = begin; i < num.size(); i++) {
            swap(num[begin], num[i]);
            permuteRecursive(num, begin + 1, result);
            swap(num[begin], num[i]);
        }
    }
};

//Recursive solution, runtime 20ms
//Using list to reduce runtime.
/*
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
		list<int> model;
		for(int i=0, max=nums.size(); i<max; i++){
			model.push_back(nums[i]);
		}
		vector<vector<int>> res;
		
		vector<int> vec;
		auto p = model.begin();
		int t;
		for(int i=0, max=nums.size(); i<max; i++){
			vec.push_back(*p);
			t = *p;
			auto q = next(p, 1);
			model.erase(p);
			cur(res,vec,model);
			model.insert(q,t);
			vec.pop_back();
			p = q;
		}
		return res;
    }
private:
	void cur(vector<vector<int>> &res, vector<int> vec, list<int> digits){
		if(!digits.empty()){
			auto p = digits.begin();
			int t;
 			for(int i=0, max=digits.size(); i<max; i++){
				vec.push_back(*p);
				t = *p;
				auto q = next(p, 1);
				digits.erase(p);
				cur(res,vec,digits);
				digits.insert(q,t);
				vec.pop_back();
				p = q;
			}
		}else{
			res.push_back(vec);
		}
	}
};
*/

