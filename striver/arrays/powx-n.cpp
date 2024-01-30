class Solution {
public:
    double myPow(double x, int n) {
        long N = n;
        if(N<0) N = N * -1;

        double ans=1.0;


        while(N>0){
            if(N%2!=0){
                ans=ans*x;
                N--;
            }
            else{
                x=x*x;
                N=N/2;
            }
        }

        if(n<0){
            ans = (double)1.0/ans;
        }

        return ans;
        
    }
};