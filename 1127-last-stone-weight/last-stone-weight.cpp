class Solution 
{
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        std::priority_queue<int> maxHeap;
        for (int i : stones)
            maxHeap.push(i);

        while (maxHeap.size() > 1)
        {
            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();
            if (stone1 == stone2)
                maxHeap.push(0);
            else
                maxHeap.push(stone1 - stone2);
        }
        return maxHeap.top();
    }
};