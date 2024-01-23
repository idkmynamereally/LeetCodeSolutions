class Solution 
{
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        if (n == 0)
            return tasks.size();
        int time{ 0 };
        std::priority_queue<int> heap;
        std::unordered_map<char, int> taskMap;      //Number of task instances remaining
        std::deque<std::pair<int, int>> que;

        for (auto c : tasks)
        {
            taskMap[c]++;
        }
        for (auto t : taskMap)
        {
            heap.push(t.second);
        }

        while (!heap.empty() || !que.empty())
        {
            if (heap.empty())
            {
                time = que.front().second;
                heap.push(que.front().first);
                que.pop_front();
            }
            time++;
            auto temp = heap.top();
            temp--;
            heap.pop();
            if (temp != 0)
                que.push_back(std::pair<int, int>(temp, time + n));
            if (!que.empty() && que.front().second <= time)
            {
                auto temp = que.front();
                que.pop_front();
                heap.push(temp.first);
            }
        }
        return time;
    }
};