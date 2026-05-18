class Solution {
public:
    int calPoints(vector<string>& operations) {
        // we have to store the info of the prev elements 
        // best ds : stack 
        // since what we have to use the LAST used element 
        // so the type used is LIFO 

        stack<int>st;
        int n=operations.size();
        for(string s:operations){
            if(s=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.push(a);
                st.push(a+b);
            }
            else if (s=="D"){
                int a =st.top();
                st.push(a*2);
            }
            else if(s=="C"){
                st.pop();
            }
            else {
                st.push(stoi(s));
            }
        }

        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};