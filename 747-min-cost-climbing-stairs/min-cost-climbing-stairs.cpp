class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        unordered_map<int, int> map;
        for (int i = cost.size() - 3; i >= 0; i--)
        {
            cost[i] += min(cost[i + 1], cost[i + 2]);
        }
        return min(cost[0], cost[1]);
    }

    //cost of going from stair i to end = min(map[i + 1], map[i + 2])
};