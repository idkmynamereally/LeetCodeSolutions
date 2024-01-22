class fartherFromOrigin
{
public:
    bool operator()(std::pair<int, double>& a, std::pair<int, double>& b)
    {
        return a.second < b.second;
    }
};

class Solution
{
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        std::priority_queue<std::pair<int, double>, std::vector<std::pair<int, double>>, fartherFromOrigin> maxHeap;

        for (int i = 0; i < points.size(); i++)
        {
            double distance = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            maxHeap.push(std::pair<int, double> (i, distance));
        }

        while (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
        
        std::vector<std::vector<int>> ans;

        while (!maxHeap.empty())
        {
            ans.push_back(points[maxHeap.top().first]);
            maxHeap.pop();
        }

        return ans;
    }
};