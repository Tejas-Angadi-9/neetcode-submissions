class Solution {
public:
    int findMin(vector<int> &nums) {
        int size = nums.size();
        int minimumValue = nums[0];

        int s = 0, e = size - 1;
        while(s <= e){
            if(nums[s] < nums[e]){
                minimumValue = min(minimumValue, nums[s]);
                break;
            }
            int mid = s + (e - s) / 2;
            minimumValue = min(minimumValue, nums[mid]);
            if(nums[s] <= nums[mid]){
                s =  mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return minimumValue;
    }
};
