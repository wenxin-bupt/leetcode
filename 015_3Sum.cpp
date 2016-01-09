/**
	Problem: 3Sum
	Link:https://leetcode.com/problems/3sum/
	Reference:https://leetcode.com/discuss/23595/share-my-solution-around-50ms-with-explanation-and-comments
	Time complexity:O(N^2)
	Runtime:52ms
**/
/**
	Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
	Find all unique triplets in the array which gives the sum of zero.

	Note:
	Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
	The solution set must not contain duplicate triplets.
**/

//52ms solution
//use two pointers
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> cache;
		int sum;
		int front, back;
		int length = nums.size();
		sort(nums.begin(), nums.end());
		int target;
		for(int i=0; i<length; i++){
			target = 0-nums[i];
			front = i+1;
			back = length-1;
			if(target<0){
				break;
			}
			while(front<back){
				sum = nums[front] + nums[back];
				if(sum>target)
					back--;
				else if(sum<target)
					front++;
				else{
					cache ={ nums[i], nums[front], nums[back]};
					result.push_back(cache);
					while(front<back&&nums[front]==cache[1])
						front++;
					while(front<back&&nums[back]==cache[2])
						back--;
				}
			}
			//i停在最后一个重复数字上，外层的for循环推了它一步.
			while(i<length-1&&nums[i+1]==nums[i])
				i++;		
		}
		return result;
	}
	
};

//Time limit exceeded solution  X_X
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> mapping;
		sort(nums.begin(),nums.end());
		int length = nums.size();
		int i=0,j,k;
		for(;i<length;i++)
			mapping[nums[i]]=i;
		i=0;
		bool flag = true;
		vector<vector<int>> result;
		vector<int> cache,cached;
		for(;i<length;i++){
			for(j=i+1;j<length;j++){
				if(mapping.find(0-(nums[i]+nums[j]))!=mapping.end()&&(k=mapping[0-(nums[i]+nums[j])])>j){
					if(flag){
						cache = {nums[i],nums[j],nums[k]};
						result.push_back(cache);
						flag = false;
					}else if(nums[i]>cache[0]||(nums[i]==cache[0]&&nums[j]>=cache[1]&&nums[k]!=cache[2])){
				        cache = {nums[i],nums[j],nums[k]};
					    result.push_back(cache);
					}
				}
			}
		}
		return result;
    }
	
};
*/