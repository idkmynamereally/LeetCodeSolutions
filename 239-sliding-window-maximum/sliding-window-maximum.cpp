class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        std::deque<int> deck;
        std::vector<int> ans;
        
        for (int i = 0; i < k; i++)     //Create deque for the first window
        {
            addToWindow(deck, nums[i]);
        }

        for (int i = 0; i <= (nums.size() - k); i++)     //Now move window while modifying the deck
        {
            ans.push_back(deck.front());
            removeLeftElement(deck, nums[i]);
            if ((i + k) < nums.size())
            {
                addToWindow(deck, nums[i + k]);
            }
        }
        return ans;
    }

    void addToWindow(std::deque<int>& deck, int num)
    {
        while ((!deck.empty()) && num > deck.back())
            deck.pop_back();
        deck.push_back(num);
    }

    void removeLeftElement(std::deque<int>& deck, int leftRemove)
    {
        if (leftRemove == deck.front())
        {
            deck.pop_front();
        }
    }
};