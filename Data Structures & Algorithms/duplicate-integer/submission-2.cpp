class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> uniqueNumbers;
        int size = nums.size();
        for(int index = 0; index < size; index++){
            if(uniqueNumbers.contains(nums[index]))
                return true;
            uniqueNumbers.insert(nums[index]);
        }
        return false;
    }
};