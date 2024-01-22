class fartherFromOrigin
{
public:
    bool operator()(std::vector<int>& a, std::vector<int>& b)
    {
        double distanceA = sqrt((double)a[0] * a[0] + a[1] * a[1]);
        double distanceB = sqrt((double)b[0] * b[0] + b[1] * b[1]);

        return distanceA < distanceB;
    }
};

class Solution 
{
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, fartherFromOrigin> maxHeap;
        
        for (const auto& p : points)
        {
            maxHeap.push(p);
        }
        while (maxHeap.size() > k)
            maxHeap.pop();

        points.clear();

        while (!maxHeap.empty())
        {
            points.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return points;
    }
};