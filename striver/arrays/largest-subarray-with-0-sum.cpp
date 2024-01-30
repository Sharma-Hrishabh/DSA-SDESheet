class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int>mp;
        int ans=0;
        int sum=0;
        for(int i=0;i<A.size();i++){
            sum+=A[i];

            // very necessary for 0 sum subarray behind an index
            if (sum == 0) ans = i + 1;
        
            if(mp.find(sum)!=mp.end()){
                ans=max(ans,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
            
        }
    return ans;

    }
};
