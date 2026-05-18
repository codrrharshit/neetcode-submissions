class Solution {
public:
    stack<char>st;
    bool counter(char ch){
        if(!st.empty() && ch==']' && st.top()=='['){
            return true;
        }
        if( !st.empty() && ch=='}' && st.top()=='{'){
            return true;
        }
         if (!st.empty() && ch==')' && st.top()=='('){
            return true;
         }
        return false;
    }
    bool isValid(string s) {
       int i=0;
       while(i<s.size()){
        char ch=s[i];
        if(ch=='[' || ch=='{' || ch=='('){
            st.push(ch);
        }
        else {
            if(counter(ch)){
                st.pop();
            }
            else {
                return false;
            }
        }
        i++;
       }

      return st.empty();
    }
};
