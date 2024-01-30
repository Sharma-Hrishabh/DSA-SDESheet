// O(n*n!)
// O(1)

class Solution {
public:
    
int jump(vector<int>& nums, int pos = 0) {
	if(pos >= size(nums) - 1) return 0;        
	int minJumps = 10001;  // initialising to max possible jumps + 1
	for(int j = 1; j <= nums[pos]; j++)  // explore all possible jump sizes from current position
		minJumps = min(minJumps, 1 + jump(nums, pos + j));        
	return minJumps;
}
};



// If you derive the recursive tree, you will see there are recalculations involved and there might be cases we can use already calculated result.


class Solution {
public:



int solve(vector<int>& nums, vector<int>& dp, int pos = 0){
    if(pos >= size(nums) - 1) return 0;        

	for(int j = 1; j <= nums[pos]; j++)  // explore all possible jump sizes from current position
		minJumps = min(minJumps, 1 + jump(nums, pos + j));        
	return minJumps;
}

int jump(vector<int>& nums, int pos = 0) {
    vector<int>dp(nums.size(),INT_MAX);
    solve(nums,dp);

}
};

