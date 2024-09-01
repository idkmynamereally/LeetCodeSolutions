class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k)
    {
        priority_queue<int> maxHeap;
        int count = 0;
        vector<int> ans;
        for (const auto& q : queries)
        {
            int x = q[0];
            int y = q[1];

            int d = abs(x) + abs(y);
            count++;
            maxHeap.push(d);

            if (count < k)
            {
                //cout << count << " " << k;
                ans.push_back(-1);
                continue;
            }
            else
            {
                while (maxHeap.size() > k)
                    maxHeap.pop();
                ans.push_back(maxHeap.top());
            }
        }
        return ans;
    }
};