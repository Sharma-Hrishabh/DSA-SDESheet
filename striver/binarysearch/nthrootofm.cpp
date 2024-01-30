#include<iostream>
using namespace std;

double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}


// 1*1*1............... M*M*M  search space
// if mid^3 > m then search in left half because mid^3 is too big
// if mid^3 < m then search in right half because mid^3 is too small
// if mid^3 == m then return mid

double binarySearch(double low,double high, int n,int m,double ep) {


	if(high-low <= ep) return low;

	double mid = (low+high)/2.0;

	if (multiply(mid, n) > m) {
		return binarySearch(low,mid,n,m,ep);
	} else {
		return binarySearch(mid,high,n,m,ep);
	}
	return low;
}

double findNthRootOfM(int n, int m) {
	double low=1;
	double high=m;

	double ep = 1e-7;

	return binarySearch(low,high,n,m,ep);


}
int main(){
    int n,m;
    // cin>>n>>m;
    n=3;
    m=27;
    cout<<findNthRootOfM(n,m);
    return 0;
}