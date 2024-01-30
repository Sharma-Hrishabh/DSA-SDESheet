// one way is :
// o(nlogn) , o(n)
// maintain a multi-map with key as as nums[i] and value as i
// it is sorted , now use algo of meet at middle and damn uou will get the key and the positions

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int,int>mp;
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<n;i++) mp.insert(make_pair(nums[i],i));
        auto i = mp.begin();
        auto j = next(mp.begin(),n-1);
        while(i!=j){
            if(i->first+j->first>target) j--;
            else if(i->first+j->first<target) i++;
            else {  
                ans.push_back(i->second);
                ans.push_back(j->second);
                break;
            }
        }

        return ans;    
    }
};

// O(N)
// Store difference of element and target in map. If difference is already present in map, then return the index of current element and the index of element whose difference is stored in map.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                ans.push_back(mp[nums[i]]);
                ans.push_back(i);
            }
            else{
                mp.insert(make_pair(target-nums[i],i));
            }
        }
        return ans;

    }
};


