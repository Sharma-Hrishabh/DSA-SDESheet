
int upperBound(vector<int>v, int key){
    int low = 0;
    int high = v.size()-1;
    // just greater than key
    while(low<=high){
        int mid = (low+high)/2;
        if(v[mid]<=key){
            // move right as just greater is not reached
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    int ub = low;
    
    return ub;
    
}

int Solution::findMedian(vector<vector<int> > &A) {
    int low = 1;
    int high = 1e9;
    int n = A.size();
    int m = A[0].size();
    
    while(low<=high){
        int mid = (high+low)/2;
        int count = 0;
        for(int i=0;i<n;i++){
            count += upperBound(A[i],mid);
        }
        //move left
        int N = (n*m)/2;
        if(count>N){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    
    return low;
    
}
