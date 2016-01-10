/**
	Problem:Insert Interval
	Link:https://leetcode.com/problems/insert-interval/
	Time complexity:O(n) 
	Runtime:576ms
**/

/**
	Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
	You may assume that the intervals were initially sorted according to their start times.
	
	Example 1:
	Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
	Example 2:
	Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
	This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
**/


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
//只添加了插入部分，merge部分和056一样
class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
		Interval cache;
		int p=0, q=1;
		int length = intervals.size();
		
		if(length==0){
			intervals.push_back(newInterval);
			return intervals;
		}
		
		for(int i=0; i<length;){
			if(intervals[i].start<=newInterval.start)
				i++;
			else{
				intervals.insert(intervals.begin()+i,newInterval);
				length++;
				break;
			}
		}
		if(length==intervals.size()){
			intervals.insert(intervals.begin()+length,newInterval);
			length++;
		}
		
		while(p<length){
			cache = intervals[p];
			while(q<length&&cache.end>=intervals[q].start){
			    if(cache.end<intervals[q].end)
				    cache.end = intervals[q].end;
				q++;
			}
			res.push_back(cache);
			p=q;
			q++;
		}
		return res;
    }
};