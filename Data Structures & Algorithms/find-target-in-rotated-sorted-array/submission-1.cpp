class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int targetIndex = -1;

        int start = 0, end = size - 1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] == target){
                targetIndex = mid;
                break;
            }
            // Is left part sorted?
            if(nums[mid] >= nums[start]){
                if(nums[start] <= target && target <= nums[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
            // Is right part sorted?
            else{
                if(nums[mid] <= target && target <= nums[end]){
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
        }
        return targetIndex;
    }
};
