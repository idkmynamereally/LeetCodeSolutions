class Twitter 
{
public:
    std::unordered_map<int, std::unordered_set<int>> users;     //<userId, <useridsfollowed>>
    std::vector<std::pair<int, int>> tweets;        //<userId, TweetId>
    Twitter() 
    {}

    void postTweet(int userId, int tweetId) 
    {
        if (!users.contains(userId))
        {
            users[userId].insert(userId);
        }
        tweets.push_back(std::pair<int, int>(userId, tweetId));
    }

    vector<int> getNewsFeed(int userId) 
    {
        std::vector<int> ans;
        int count = 0;
        for (int i = tweets.size() - 1; i >= 0; i--)
        {
            if (count == 10)
                break;
            auto tweet = tweets[i];
            if (users[userId].contains(tweet.first))
            {
                count++;
                ans.push_back(tweet.second);
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) 
    {
        if (!users.contains(followerId))
        {
            users[followerId].insert(followerId);
        }
        if (!users.contains(followeeId))
        {
            users[followeeId].insert(followeeId);
        }
        users[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) 
    {
        if (!users.contains(followerId))
        {
            users[followerId].insert(followerId);
        }
        if (!users.contains(followeeId))
        {
            users[followeeId].insert(followeeId);
        }
        users[followerId].erase(followeeId);
    }
};