class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        for (int i = 0; i < timePoints.size(); i++)
        {
            string s = timePoints[i];
            string hr = s.substr(0, 2);
            string mins = s.substr(3, 2);
            int hours = stoi(hr);
            int min = stoi(mins);
            time.push_back(hours*60 + min);
        }
        sort(time.begin(), time.end());

        int ans = INT_MAX;
        for (int i = 0; i < time.size(); i++)
        {
            int t = abs(time[(i + 1) % time.size()] - time[i]);
            ans = ans < t ? ans : t;
            t = 1440 - t;
            ans = ans < t ? ans : t;
        }
        return ans;
    }
};