class Solution {

public:
   string mp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    
    void getProduct(string digits,string res,int expand,vector<string>&ans){
        if(expand>=digits.length()){
            ans.push_back(res);
            return;
        }
        int num = digits[expand]-'0';
        string temp = mp[num];
       // expand++;
        
        for(int i=0;i<temp.length();i++){
         //   res.push_back(temp[i]);
            res+=temp[i];
            getProduct(digits,res,expand+1,ans);
            res.pop_back();
            
        }
        
    }
    
    
    
    vector<string> letterCombinations(string digits) {
      
        // idea is to do a recursion call for each digit and then for each letter in the digit
        // and then for each letter in the next digit and so on

        //'23'
        // expand 2 and with each char [ a loop]in expansion do a recursion call for 3 and so on
        // while chossing a character in the expansion of 2, we will also add that character to the result string, and for the next case do backtracking

        // when we have expanded all character return output

        vector<string>ans;
      
        if(digits.length()==0) return ans;
        getProduct(digits,"",0,ans);
        
        return ans;
        
    }
};


// https://www.youtube.com/watch?v=tWnHbSHwNmA