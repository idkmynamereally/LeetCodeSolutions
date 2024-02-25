class Solution
{
public:
    bool isNStraightHand(vector<int>& hand, int groupSize)
    {
        int size = hand.size();
        if ((size % groupSize) != 0)
            return false;
        std::sort(hand.begin(), hand.end());
        std::map<int, int> m;
        for (int i : hand)
        {
            m[i]++;
        }
        for (int i = 0; i < hand.size(); i++)
        {
            if (m[hand[i]])
            {
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