class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.size() == 1)
            return 0;
        int buy = 0;
        int sell = 1;
        int maxProfit = 0;

        for (sell; sell < prices.size(); sell++)
        {
            if (prices[sell]-prices[buy] > maxProfit)
            {
                maxProfit = prices[sell]-prices[buy];
            }
            if (prices[sell] < prices[buy])
            {
                buy = sell;
            }
        }
        return maxProfit;
    }
};