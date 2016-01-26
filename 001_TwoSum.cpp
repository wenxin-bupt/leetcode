//2015 12 31 22:23

class Solution {
	public:
		vector<int> twoSum(vector<int> &nums, int target){
			unordered_map<int,int> mapping;
			for(int i=0; i < nums.size(); i++){
			    if(mapping.find(target-nums[i])!=mapping.end())
					return {mapping[target-nums[i]]+1,i+1};
				mapping[nums[i]] = i;
			}
		};
};
