class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int j=0;
        int minlength=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            // shrinking the window 
            while(sum>=target){
                minlength=min(minlength,i-j+1);
                // removing the element from the left side 
                sum-=nums[j];
                j++;
            }
        }
        return minlength==INT_MAX?0:minlength;
    }
};