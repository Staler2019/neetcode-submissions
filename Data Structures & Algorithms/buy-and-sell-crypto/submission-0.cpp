class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = static_cast<int>(prices.size());
        vector<int> maxSoldOut(n);

        maxSoldOut[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxSoldOut[i] = max(prices[i], maxSoldOut[i+1]);
        }

        int maxProfit = 0;
        for (int i = prices.size() - 2; i >= 0; i--){
            maxProfit = max(maxProfit, maxSoldOut[i] - prices[i]);
        }

        return maxProfit;
    }
};
