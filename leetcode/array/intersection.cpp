// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.


// Unsorted Approaches

// 1. Using unordered_map - O(n + m), O(min(n,m))
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int n = nums1.size();
        int m = nums2.size();


        for(int i=0;i<n;i++)
        {
            mp.insert(make_pair(nums1[i],1));
        }
        for(int i=0;i<m;i++)
        {
            auto itr = mp.find(nums2[i]);
            if(itr !=mp.end() && itr->second==1 ) {
                ans.push_back(nums2[i]);
                mp[nums2[i]]=2;
            }
        }
        return ans;
    }
};
// 2. Using sorting - O(nlogn), O(n) 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
 
         vector<int>mp;
        int n = nums1.size();
        int m = nums2.size();

       sort(nums1.begin(),nums1.end());
       sort(nums2.begin(),nums2.end());


       //4,5,9
       //4,4,8,8,9

       for(int i=0,j=0;i<n && j<m;){
           if(nums1[i]==nums2[j]) {
               if(mp.size()==0 || mp[mp.size()-1]!=nums1[i])    // to avoid duplicates, the last value inserted shouldnt be same as the new common
                   mp.push_back(nums1[i]);
               i++;
               j++;
           }
           else if (nums1[i]>nums2[j]) j++;
           else i++;
       }

        return mp;
    }
    };
