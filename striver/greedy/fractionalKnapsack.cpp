class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    bool static comparator(Item a, Item b){
        double r1 = double(a.value)/double(a.weight);
        double r2 = double(b.value)/double(b.weight);
        return ( r1>r2 );
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        // idea is to sort the array on basis of value/weight
        sort(arr,arr+n,comparator);
        
        double maxProfit=0;
        int currW=0;
        for(int i=0;i<n;i++){
            if(currW<=W){
                if(currW+arr[i].weight<=W){
                    maxProfit += arr[i].value;
                    currW+= arr[i].weight;
                }
                else{
                    // break item
                    double pV = double(arr[i].value) / double(arr[i].weight);
                    int remCap = W-currW;
                    currW = W;
                    maxProfit += double(remCap) * pV;
                }
                
            }
        }
        return maxProfit;
    }
        
};