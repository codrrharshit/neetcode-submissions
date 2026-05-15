class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        for(int k=0;k<nums.size();k++){
            if(k>0 && nums[k]==nums[k-1]) continue;
            int target=-nums[k];
            int i=k+1;
            int j=nums.size()-1;
            // we have to find the two sum 
            while(i<j){
                int sum= nums[i]+nums[j];
                if(sum==target){
                    result.push_back({nums[i],nums[j],nums[k]});
                            // we have to skip all the duplicates i and j
                        while(i<j && nums[i]==nums[i+1])i++;
                        while(i<j && nums[j]==nums[j+1])j++;

                    i++;
                    j--;// for finding new triplet;
                }
                else if (sum<target){
                    i++;
                }
                else {
                    j--;
                }
            }
        }

        return result;
    }
};
