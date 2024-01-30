// O(n)
// O(n)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        //unordered_set<vector<string>>s;
        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            if(mp.find(temp)!=mp.end()) mp[temp].push_back(strs[i]);
            else{
                vector<string>v;
                v.push_back(strs[i]);
                mp[temp]=v;
            }
            
        }
        
        vector<vector<string>>ans;
        
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            ans.push_back(itr->second); 
        }
        
        return ans;
        
    }
};