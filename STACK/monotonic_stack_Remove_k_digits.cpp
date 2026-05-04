class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();

        
        string res = "";
        for(int i =0; i<n ;i++){
            while(res.length() >0 && res.back()> num[i] && k>0){
                res.pop_back();
                k--;

            }
            if(res.length()>0 || num[i]!='0'){ //to avoid the case when we have preceeding zeros
                res.push_back(num[i]);
            }
        }
        //if already in increasing order so that we have to remove the last k elements from the result string

        while(res.length()>0 && k>0){
            res.pop_back();
            k--;
        }
        if(res =="") return "0";
        
        return res;
        
    }
};
