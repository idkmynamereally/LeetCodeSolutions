class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b)
             {
                return a[0] < b[0];
             });

        vector<vector<int>> ans;
        int n = intervals.size();
        vector<int> curr{intervals[0]};

        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] <= curr[1])
            {
                curr[1] = curr[1] > intervals[i][1] ? curr[1] : intervals[i][1];
                continue;
            }
            ans.push_back(curr);
            curr[0] = intervals[i][0];
            curr[1] = intervals[i][1];
        }
        ans.push_back(curr);
        return ans;
    }
};