class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int profit = 0, low = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            profit = max(profit, prices[i]-low);
            low = min(low, prices[i]);
        }
        return profit;
    }
};