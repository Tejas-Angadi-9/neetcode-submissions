class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximumProfit = 0;
        int minimumProfit = INT_MAX;
        for(int i=0; i<prices.size(); i++){
            minimumProfit = min(minimumProfit, prices[i]);
            int profit = prices[i] - minimumProfit;
            maximumProfit = max(profit, maximumProfit);
        }
        return maximumProfit;
    }
};
