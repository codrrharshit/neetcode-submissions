class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int s:nums){
            freq[s]++;
        }

        // defining the priority queue 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        for( auto &entry :freq){
            minheap.push({entry.second,entry.first});

            if(minheap.size()>k){
                minheap.pop();
            }
        }

        vector<int>result;
        while(!minheap.empty()){
            result.push_back(minheap.top().second);
            minheap.pop();
        }

        return result;

    }
};
