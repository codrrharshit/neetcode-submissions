class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        int j=0;
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            // while adding the element in the sequence if the 
            if(abs(i-j)>k){
                s.erase(nums[j]);
                j++;
            }
            if(s.count(nums[i])>0){
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};