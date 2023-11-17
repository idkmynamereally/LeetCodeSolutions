class Solution 
{
public:
    bool fleet(std::pair<int, int> behind, std::pair<int, int> ahead, int target)
    {
        double t1 = (target - behind.first) / (double)behind.second;
        double t2 = (target - ahead.first) / (double)ahead.second;
        if (t1 <= t2)
            return true;
        return false;
    }

    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        if (position.size() == 1)
            return 1;
        
        std::vector < std::pair<int,int> > posSpeed(position.size());
        for (int i = 0; i < position.size(); i++)
        {
            posSpeed[i] = std::pair(position[i], speed[i]);
        }
        std::sort(posSpeed.begin(), posSpeed.end(),
            [](std::pair<int,int> a, std::pair<int, int> b)
                  {
                      return a.first < b.first;
                  }
        );
        std::stack<std::pair<int, int>> st;
        int ans{ 1 };
        for (const auto& i : posSpeed)
        {
            st.push(i);
        }
        while (!st.empty())
        {
            auto top = st.top();
            st.pop();
            while (!st.empty())
            {
                auto behind = st.top();
                st.pop();
                if (fleet(behind, top, target))
                {
                    continue;
                }
                else
                {
                    ans++;
                    top = behind;
                }
            }
        }
        return ans;
    }
};