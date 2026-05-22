class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int n = nums.size();

        for(int num : nums){
            mpp[num]++;
        }

        vector<pair<int, int>> countArr;
        for(const auto& it : mpp){
            countArr.push_back({it.second, it.first});
        }

        vector<int> topKFrequentValues(k);
        for(int i=0; i<k; i++){
            topKFrequentValues[i] = countArr[i].second;
        }
        return topKFrequentValues;
    }
};
