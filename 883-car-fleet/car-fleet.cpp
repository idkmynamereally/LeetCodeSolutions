class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;

        for (int i = 0; i < speed.size(); i++)
        {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), 
            [](const pair<int, int> a, const pair<int, int> b)
            {
                return a < b;
            });
        
        stack<float> st;
        for (int i = 0; i < cars.size(); i++)
        {
            int d = target - cars[i].first;
            float t = (float) d / cars[i].second;

            cout << t << " ";

            while (!st.empty() && st.top() <= t)
            {
                st.pop();
            }
            st.push(t);
        }

        return st.size();
    }
};