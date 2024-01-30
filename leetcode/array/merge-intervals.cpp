/*
Approach-1: O(nlogn)
- Sort the intervals
- Merge the intervals

if  the second of first interval is greater than the first of second interval, then merge is possible
else add the first interval to the result

while merging take the maximum of second interval among both the intervals (if one is subset then it will cover)

*/

class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        for(int i = 0;i<n-1;i++){
            if(intervals[i][0]==-1) continue;
            for(int j = i+1; j<n;j++){
                if(intervals[j][0]==-1) continue;
                // of the end of the first interval is greater than the start of the second interval, it means they overlap
                if(intervals[i][1]>=intervals[j][0]){
                        intervals[i][1] = max(intervals[i][1] ,intervals[j][1]); // 1-6 2-3   , 1-6 2-7   examples of subset and non-subset while merging
                        intervals[j][0]=-1;
                        intervals[j][1]=-1;                                            
                }
                
            }
        }
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            if(intervals[i][0]==-1) continue;
            else ans.push_back(intervals[i]); 
        }
        
        return ans;
        
    }
};



//leetcode easy solution for nlogn

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (auto interval : intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};