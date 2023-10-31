class Solution {
public:
    int trap(std::vector<int>& height)
    {
        if (height.size() == 0)
            return 0;
        int ans{};
        int n{ static_cast<int>(height.size()) };
        std::vector<std::pair<int, int>> banks(n);     //Stores the tallest left and right bank for all positions

        banks[0].first = 0;
        banks[n - 1].second = 0;

        for (int i = 1; i < n; i++)
        {
            banks[i].first = std::max(banks[i - 1].first, height[i - 1]);
        }

        int waterHeight{};
        for (int i = n - 2; i >= 0; i--)
        {
            banks[i].second = std::max(banks[i+1].second, height[i+1]);
            
            waterHeight = std::min(banks[i].first, banks[i].second);
            if (height[i] >= waterHeight)
                continue;
            ans += waterHeight - height[i];
        }
        return ans;
    }
};