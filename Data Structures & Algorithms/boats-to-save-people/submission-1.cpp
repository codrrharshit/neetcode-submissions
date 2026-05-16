class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        // again we can apply the same logic of pairs of number 
        // using two pointer 
        int n=p.size();
        int i=0;
        int j=n-1;
        int count=0;
        sort(p.begin(),p.end());
        while(i<j){
            if(p[i]+p[j]<=limit){
                count++;
                i++;
                j--;
            }
            else if ((p[i]+p[j])>limit){
                j--;
            }
            
        }

        return n-count;
    }
};