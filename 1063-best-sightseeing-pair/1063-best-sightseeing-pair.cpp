class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max = values[0];
        int ans = -1;
        for (int i = 1; i < values.size(); i++)
        {
            int t = values[i] - i + max;
            ans = ans > t ? ans : t;
            values[i] = values[i] + i;
            max = max > values[i] ? max : values[i];
        }

        return ans;
    }
};