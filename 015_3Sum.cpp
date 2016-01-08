class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> mapping;
		sort(nums.begin(),nums.end());
		//unique(nums.begin(),nums.end());
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
						cached = {nums[i],nums[j],nums[k]};
						flag = false;
					}
				    cache ={nums[i],nums[j],nums[k]} ;
					if( cache != cached && nums[0]>=cached[0]&&nums[1]>=cached[1]){
				        cached = {nums[i],nums[j],nums[k]};
					    result.push_back(cache);
					}
					
				}
			}
		}
		return result;
    }
	
};
