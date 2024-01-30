
//O(nlog), O(1)
class Solution {
public:
    int firstUniqChar(string s) {
    vector<int>v(26,-2);
        
    for(int i=0;i<s.length();i++){
        if(v[s[i]-'a']>=0) v[s[i]-'a']=-1;  // the char has appeared before so set to -1 to denote repeat
        else if(v[s[i]-'a']==-2) v[s[i]-'a']=i; //apearing first time
        else continue; //for the case we know it has appeared before and set to -1
    }
        
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(v[i]>=0) return v[i];
    }
    return -1;
    }
};

