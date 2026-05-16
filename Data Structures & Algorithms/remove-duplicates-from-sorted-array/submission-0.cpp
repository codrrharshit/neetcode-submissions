class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=0;
        // we have to take a pointer where we have to put the element 
        int k=0;
        while(j<nums.size()){
            while(nums[i]==nums[j]){
                j++;
            }
            nums[k]=nums[i];
            i=j;
            k++;
        }

        return k ;
    }
};