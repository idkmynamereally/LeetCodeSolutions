class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h)
    {
        cout.tie(0);
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        
        auto maxer{ *std::max_element(piles.begin(), piles.end()) };
        
        int left{ 1 };
        int right{ maxer };
        int middle{};

        while (left != right)
        {
            middle = left + floor((right - left) / 2);
            auto midWorking = checkK(piles, h, middle);

            if (midWorking)
                right = middle;
            else
                left = middle + 1;
        }

        return left;
    }

    bool checkK(std::vector<int>& piles, int h, int k)
    {
        for (int p : piles)
        {
            h -= ceil((double)p / k);
            if (h < 0)
                return false;
        }
        return true;
    }
};