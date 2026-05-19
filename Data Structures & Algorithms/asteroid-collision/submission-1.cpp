class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>st; // we will add positive as well as negative 

        for (int x:a){
            bool destroyed=false;
            while(!st.empty() && st.top()>0 && x<0){
                if(st.top()<abs(x)){
                    st.pop();
                }
                else if (st.top()== abs(x)){
                    st.pop();
                    destroyed=true;
                    break;
                }
                else {
                    destroyed=true;
                    break;
                }
            }

            if(!destroyed){
                st.push(x);
            }
        }

        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};