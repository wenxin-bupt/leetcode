/**
	Problem: Merge Intervals
	Link:https://leetcode.com/problems/merge-intervals/
	Time complexity:O(nlogn) 
	Runtime:588ms
**/

/**
	Given a collection of intervals, merge all overlapping intervals.
	For example,
	Given [1,3],[2,6],[8,10],[15,18],
	return [1,6],[8,10],[15,18].
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
 //sort的用法
 //sort不能保证排序结果是稳定的
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
		Interval cache;
		int p=0, q=1;
		int length = intervals.size();
		if(length<2)
			return intervals;
		sort(intervals.begin(),intervals.end(),myFunction);	    
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
	static bool myFunction(const Interval& p, const Interval& q){
		return p.start<q.start;
	}
};