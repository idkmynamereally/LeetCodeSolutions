class TimeMap {
public:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> m;
    TimeMap() 
    {
        
    }

    void set(std::string key, std::string value, int timestamp) 
    {
        m[key].push_back(std::pair(timestamp, value));
    }

    std::string get(std::string key, int timestamp)
    {
        if (!m.contains(key))
            return "";
        int left{ 0 };
        int right = m[key].size() - 1;
        int middle{};
        int midTimeStamp;

        while (left <= right)
        {
            middle = left + floor((right - left)/ 2);
            std::cout << "mid : " << middle;
            midTimeStamp = m[key][middle].first;
            if (midTimeStamp == timestamp)
            {
                return m[key][middle].second;
            }
            else if (midTimeStamp < timestamp)
            {
                left = middle + 1;
            }
            else if (midTimeStamp > timestamp)
            {
                right = middle - 1;
            }
        }        
        if (timestamp < m[key][0].first)
            return "";
        while (middle > 0 && midTimeStamp > timestamp)
        {
            middle--;
            midTimeStamp = m[key][middle].first;
        }
        return m[key][middle].second;
    }
};