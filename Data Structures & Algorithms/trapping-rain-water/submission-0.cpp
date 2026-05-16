class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        // we have to store the max left to that index and right to that index 
        vector<int>maxl(n,0),maxr(n,0);
        int maxe=0;
        for(int i=0;i<n;i++){
            maxe=max(maxe,h[i]);
            maxl[i]=maxe;
        }
        maxe=0;
        for(int i=n-1;i>=0;i--){
           maxe=max(maxe,h[i]);
            maxr[i]=maxe;
        }

        // for each element we have to find the water stored and add to the ans
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(maxl[i],maxr[i])-h[i];
        }
        return ans;
    }
};
