class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestCount = 0;
        set<int> sortedSet(nums.begin(), nums.end());

        for(int st : sortedSet){
            int count = 0;
            int previousStart = st - 1;
            if(sortedSet.find(previousStart) == sortedSet.end()){
                int count = 1;
                int x = st + 1;
                while(sortedSet.find(x) != sortedSet.end()){
                    count++;
                    x++;
                }
                longestCount = max(count, longestCount);
            }
        }

        return longestCount;
    }
};
