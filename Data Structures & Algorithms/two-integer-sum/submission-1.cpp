class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Step 1: Create a vector of pairs to store {value, index}
        vector<pair<int, int>> numIndex;
        for (int i = 0; i < nums.size(); i++) {
            numIndex.push_back({nums[i], i});
        }
        
        // Step 2: Sort the vector based on the values
        sort(numIndex.begin(), numIndex.end());
        
        // Step 3: Two-pointer approach
        int i = 0;
        int j = nums.size() - 1;
        
        while (i < j) {
            int sum = numIndex[i].first + numIndex[j].first;
            if (sum == target) {
                // Collect the original indices
                int idx1 = numIndex[i].second;
                int idx2 = numIndex[j].second;
                // Return the indices in sorted order
                return {min(idx1, idx2), max(idx1, idx2)};
            } else if (sum < target) {
                i++; // Move the left pointer to increase the sum
            } else {
                j--; // Move the right pointer to decrease the sum
            }
        }
        
        return {}; // Return an empty vector if no solution exists
    }
};
