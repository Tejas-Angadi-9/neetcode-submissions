class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestCount = 0;
        set<int> numSet(nums.begin(), nums.end());

        for(int num : numSet){
            if(numSet.find(num - 1) == numSet.end()){
                int length = 1;
                while(numSet.find(num + length) != numSet.end()){
                    length++;
                }
                longestCount = max(length, longestCount);
            }
        }

        return longestCount;
    }
};
