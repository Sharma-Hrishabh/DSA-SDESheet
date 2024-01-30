class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    // it doesnt matter after sorting the apur of arrival dep, what matters is on arrival of a train is there a train at platform which has not deparyed yet
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int i=1;
    	int j=0;
    	int maxP = 1;
    	int p=1;
    	
    	while(i<n && j<n){
    	    if(arr[i]<=dep[j]){
                //train arrived
    	        p++;
    	        i++;
    	    }
    	    else{
                //train departed
    	        p--;
    	        j++;
    	        
    	    }
    	    maxP = max(maxP,p);
    	}
    	
    	return maxP;
    }
};