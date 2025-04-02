//here i am using isdigit() function to check whether the char in given string is numeric or not 
//2nd thing is string is passsed by referece and by char * so use strlen function to find the size of the given string 
int myAtoi(char *s) {
        // Your code here
        int idx = 0;
        int sign = 1;
        int n =strlen(s);
        long res = 0;
        while(idx<n && s[idx]==' ') idx++;
        if(idx == n) return 0;
        if( s[idx]=='-')
        {
            sign =-1;
            idx++;
            
        }
        else if(s[idx]=='+') idx++;
        while(idx<n && isdigit(s[idx]))
        {
            res = res* 10 + (s[idx]-'0');
            if(res*sign > INT_MAX) return INT_MAX;
            if(res*sign < INT_MIN) return INT_MIN;
            idx++;
            
        }
        return (int)(sign* res);
    }
