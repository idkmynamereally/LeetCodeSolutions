class Solution
{
public:
    bool isNStraightHand(vector<int>& hand, int groupSize)
    {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int size = hand.size();
        if ((size % groupSize) != 0)
            return false;
        std::sort(hand.begin(), hand.end());
        std::unordered_map<int, int> m;
        for (int i : hand)
        {
            m[i]++;
        }
        for (int i = 0; i < hand.size(); i++)
        {
            if (m[hand[i]])
            {
                int card = hand[i];
                for (int card = hand[i]; (card - hand[i]) < groupSize; card++)
                {
                    if (m[card] == 0)
                    {
                        return false;
                    }
                    m[card]--;
                }
            }
        }
        return true;
    }
};