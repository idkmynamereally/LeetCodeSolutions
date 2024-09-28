class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int ans = 0;
        int buy = prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] <= buy)
                buy = prices[i];
            else
                ans = ans > (prices[i] - buy) ? ans : (prices[i] - buy);
        }
        return ans;
    }
};