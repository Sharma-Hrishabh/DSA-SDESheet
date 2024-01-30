

bool isPossible(vector<int> &A, int B,int barrier){
    int counter=1;
    int pages=0;
    for(int i=0;i<A.size();i++){
        // any value exceeds barrier
        if(A[i]>barrier) return false;
        // keep allcoating to the same student
        if(A[i]+pages<=barrier){
            pages += A[i];
        }
        else{
            // bring a new student
            counter++;
            
            if(counter>B) return false;
            
            pages = A[i];
        }
    }
    return true;
}


int Solution::books(vector<int> &A, int B) {
     if (B > A.size()) return -1;
     
    int low=INT_MAX;
    int high=0;
    int n = A.size();
    for(int i=0;i<n;i++){
        low = min(low,A[i]); // suppose [12 12 12 12] among B=4 
        high += A[i]; // suppose [ 12 33 45 454] among B=1
    }

    // search space is [low,high]

    int res=-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(isPossible(A,B,mid)){
            // can be allocated, lets minify by lowering the barrier
            res=mid;
            high = mid-1;
        }
        // can't be allocated, lets increase the barrier
        else low=mid+1;
    }
    return res;
}
