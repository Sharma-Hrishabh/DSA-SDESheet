#include<iostream>
#include<vector>
using namespace std;


// TLE solution
class Solution {
public:
    void getPerm(string &s,int l,int r,vector<string>&res){
        if(l==r) {
            res.push_back(s);
            return;
        }

        for(int i=l;i<=r;i++){
            swap(s[i],s[l]);
            getPerm(s,l+1,r,res);
            swap(s[l],s[i]);
        }

    }


    string getPermutation(int n, int k) {
        vector<string>res;
        string s="";
        for(int i=1;i<=n;i++){
            s+= (i+'0');
        }

        getPerm(s,0,n-1,res);

        for(int i=0;i<res.size();i++){
            cout<<res[i]<<endl;
        }
        sort(res.begin(),res.end());
        return res[k-1];

    }
};

class Solution2 {
public:

    string getPermutation(int n, int k) {
        vector<int>nums;
        string ans="";
        int fact=1;
        for(int i=1;i<n;i++){
            fact*=i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k--;

        while(nums.size()>0){
            int index = k/fact;
            k = k%fact;
            ans+= (nums[index]+'0');
            nums.erase(nums.begin()+index);
            if(nums.size()>0) fact/=nums.size();
        }
        return ans;

    }
};

int main(){
    Solution2 s;
    cout<<s.getPermutation(3,3);
}