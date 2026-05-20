class Solution {
public:
    int maxArea(vector<int>& heights) {
        int size = heights.size();
        int leftPtr = 0, rightPtr = size - 1;
        int result = 0;

        while(leftPtr < rightPtr){
            int minHeight = min(heights[leftPtr], heights[rightPtr]);
            int area = minHeight * (rightPtr - leftPtr);
            result = max(result, area);

            if(heights[leftPtr] <= heights[rightPtr])   leftPtr++;
            else rightPtr--;
        }
        return result;
    }
};
