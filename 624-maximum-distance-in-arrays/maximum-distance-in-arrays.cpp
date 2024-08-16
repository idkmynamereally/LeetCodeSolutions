class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays)
    {
        int min = arrays[0][0];
        int max = arrays[0][arrays[0].size() - 1];
        int ans = INT_MIN;
        for (int i = 1; i < arrays.size(); i++)
        {
            int l = arrays[i][0];
            int r = arrays[i][arrays[i].size() - 1];

            int t1 = abs(l - max);
            int t2 = abs(r - min);

            int t = t1 > t2 ? t1 : t2;
            ans = ans > t ? ans : t;

            min = min < l ? min : l;
            max = max > r ? max : r;
        }
        return ans;
    }
};

//no matter how the current arr min max are set up, any min will give best answer with maxSofar and
//any max will make pair with minSofar trust me.