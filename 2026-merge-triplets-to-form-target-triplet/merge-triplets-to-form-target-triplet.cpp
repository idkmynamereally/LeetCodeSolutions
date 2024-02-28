#pragma GCC optimize("03")

static int __star = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    return 0;
}();

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
        for (const auto& t : triplets)
        {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2])
                continue;
            if (t[0] == target[0])
                p1 = true;
            if (t[1] == target[1])
                p2 = true;
            if (t[2] == target[2])
                p3 = true;
            if (p1 && p2 && p3)
                return true;
        }
        return false;
    }
};