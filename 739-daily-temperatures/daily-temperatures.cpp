class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        ios_base::sync_with_stdio(0),cin.tie(0);
        stack<pair<int, int>> st;
        vector<int> ans(temp.size(), 0);
        for (int i = 0; i < temp.size(); i++)
        {
            while (!st.empty() && temp[i] > st.top().first)
            {
                ans[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temp[i], i});
        }
        return ans;
    }
};