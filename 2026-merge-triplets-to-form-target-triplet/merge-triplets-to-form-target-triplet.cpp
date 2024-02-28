class Solution
{
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target)
    {
        unordered_set<int> set;
        for (int i = 0; i < triplets.size(); i++)
            set.insert(i);
        bool p1 = false;
        bool p2 = false;
        bool p3 = false;
        for (int i = 0; i < triplets.size(); i++)
        {
            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2])
                continue;
            if (triplets[i][0] == target[0])
                p1 = true;
            if (triplets[i][1] == target[1])
                p2 = true;
            if (triplets[i][2] == target[2])
                p3 = true;
            if (p1 && p2 && p3)
                return true;
        }
        return false;
    }
};