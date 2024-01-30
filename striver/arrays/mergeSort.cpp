class Solution {
public:
    vector<int> merge(vector<int>lA,vector<int>rA){
        int nL = lA.size();
        int nR = rA.size();
        vector<int> ans;
        int i=0;
        int j=0;

        while(i<nL && j<nR){
            if(lA[i]<=rA[j]){
                ans.push_back(lA[i]);
                i++;
            }
            else{
                ans.push_back(rA[j]);
                j++;
            }
        }

        while(i<nL){
            ans.push_back(lA[i]);            
            i++;
        }
        while(j<nR){
            ans.push_back(rA[j]);            
            j++;
        }        

        return ans;
    }

    vector<int> mergeSort(vector<int>& nums,int l, int r){
        if(l==r) {
            vector<int>temp;
            temp.push_back(nums[l]);
            return temp;
        }

        int mid = l+(r-l)/2;

        vector<int> lArray = mergeSort(nums,l,mid);
        vector<int> rArray = mergeSort(nums,mid+1,r);

        return merge(lArray,rArray);
    }


    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};




