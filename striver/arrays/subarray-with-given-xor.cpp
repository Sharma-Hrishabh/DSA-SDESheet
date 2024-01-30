#include<iostream>

#include<vector>
#include<map>
using namespace std;

class Solution {

public:
    int solve(vector<int> &A, int B);
};

int Solution::solve(vector<int> &A, int B) {
    int count=0;
    map<int,int>mp;
    
    int xr = 0;
    for(int i=0;i<A.size();i++){
        xr = xr ^ A[i];
        if(xr==B) count++;
        
        int y = xr ^ B;
        
        if(mp.find(y)!=mp.end()){
            count+= mp[y];
        } 
        
        mp[xr]+=1;
       
        
    }
    
    return count;
    

}


int main() {
    Solution s;
    vector<int> A = {4, 2, 2, 6, 4};
    int B = 6;
    cout<<s.solve(A,B)<<endl;
    return 0;
}

// O(N^2) solution
// int Solution::solve(vector<int> &A, int B) {
//     int count=0;
//     for(int i=0;i<A.size();i++){
//         int temp=0;
//         for(int j=i;j<A.size();j++){
//             // subarray with i to j
//             temp = temp ^ A[j];
            
//             if(temp==B) count++;
//         }
//     }
//     return count;
// }
