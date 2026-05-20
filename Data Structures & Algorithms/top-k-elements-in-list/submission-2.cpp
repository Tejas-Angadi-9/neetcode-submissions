class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        vector<vector<int>> count(nums.size() + 1);

        for(int num : nums){
            mpp[num]++;
        }

        for(const auto& it : mpp){
            count[it.second].push_back(it.first);
        }
        
        vector<int> ans;
        for(int i=count.size()-1; i>0; i--){
            for(int it : count[i]){
                ans.push_back(it);
                if(ans.size() >= k){
                    return ans;
                }
            }
        }
        return ans;
    }
};
