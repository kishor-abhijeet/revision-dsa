class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<long long> st;
        long long num = 0;
        int res = 0;
        int sign = 1;

        for(int i =0; i< n; i++){
            if(isdigit(s[i])){
                num = num*10 + (s[i]-'0');

            }else if(s[i] == '+'){
                res += (num*sign);
                num = 0;
                sign = 1;
            }else if(s[i] ==  '-'){
                res += (num * sign);
                num = 0;
                sign = -1;

            }else if(s[i] == '('){
                st.push(res);
                st.push(sign);
                res = 0;
                num = 0;
                sign = 1;//new begin ho raha hai 
            }else if(s[i] == ')'){
                 res += sign*num;
                num = 0;
                int top = st.top(); st.pop();
                res *= top;
                top = st.top(); st.pop();
                res += top;
            }

        }
        res +=  (sign * num);
        return res;
    }
};
