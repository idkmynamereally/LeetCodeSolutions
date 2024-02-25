class Solution
{
public:
    Solution()
    {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    }
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
            //std::cout << hand[i] << "\n";
            if (m[hand[i]])
            {
                int card = hand[i];
                for (int count = 0; count < groupSize; count++)
                {
                    if (m[card] == 0)
                    {
                        return false;
                    }
                    //std::cout << card << ", ";
                    m[card]--;
                    card++;
                }
                //std::cout << "\n";
            }
        }
        return true;
    }
};