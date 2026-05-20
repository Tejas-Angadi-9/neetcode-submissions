class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        // Find the prefix array
        vector<int> prefix(n, 0);
        int prefixProduct = 1;
        for(int i=0; i<n; i++){ 
            prefixProduct *= nums[i];
            prefix[i] = prefixProduct;
        }

        // Find the postfix array
        vector<int> postfix(n, 0);
        int postfixProduct = 1;
        for(int i=n-1; i>=0; i--){
            postfixProduct *= nums[i];
            postfix[i] = postfixProduct;
        }

        // Iterate the array and multiple the prefix and the postfix for that index ie. i-1 and i+1 for prefix and postfix respectively
        int product = 1;
        for(int i=0; i<n; i++){
            if(i>0 && i<n-1)
                product = prefix[i-1] * postfix[i+1];
            else if(i == 0)
                product = 1 * postfix[i+1];
            else
                product = prefix[i-1] * 1;
                
            ans[i] = product;
        }
        return ans;
    }
};
