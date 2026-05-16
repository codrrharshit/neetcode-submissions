class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // we have to reverse the array 3 times
        int n=nums.size();
        k=k%n; 
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};