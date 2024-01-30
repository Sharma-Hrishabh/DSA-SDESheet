// 1,2,3
// 1,2,4
// 0,0,0,0  //sum
// 0,0,0,1 //carry
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int>carry(n+1);
        vector<int>sum(n+1);
          carry[n]=1;

        for(int i=n-1;i>=0;i--)
        {
            if(carry[i+1]+digits[i]==10){
                carry[i]=1;
                sum[i+1]=0;
            }
            else{
                sum[i+1]=digits[i]+carry[i+1];
            }
        }
        if(carry[0]==1) sum[0]=1;
        if(sum[0]==0) sum.erase(sum.begin());        
        return sum;
    }
};