class Solution 
{
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w)
    {
        if (points.size() == 0)
            return 0;
        sort(points.begin(), points.end());

/*        for (auto point : points)
        {
            cout << point[0] << " " << point[1] << "\n";
        }
*/
        int ans = 1;
        int l = points[0][0];
        int r = points[0][0];

        for (int i = 0; i < points.size(); i++)
        {
            if (points[i][0] > r)
            {
                if (points[i][0] - l > w)
                {
                    ans++;
                    l = points[i][0];
                    r = points[i][0];
                    continue;
                }
                r = points[i][0];
            }
        }

        return ans;
    }
};