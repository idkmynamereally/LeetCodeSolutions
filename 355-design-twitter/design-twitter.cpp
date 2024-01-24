class Twitter 
{
public:
    std::unordered_map<int, std::unordered_set<int>> users;     //<userId, <useridsfollowed>>
    std::vector<std::pair<int, int>> tweets;        //<userId, TweetId>
    Twitter() 
    {
        tweets.reserve(10);
    }

    void postTweet(int userId, int tweetId) 
    {
        tweets.push_back(std::pair<int, int>(userId, tweetId));
    }

    vector<int> getNewsFeed(int userId) 
    {
        int count = 0;
        std::vector<int> ans;
        for (int i = tweets.size() - 1; i >= 0; i--)
        {
            if (count == 10)
                break;
            auto tweet = tweets[i];
            if (users[userId].contains(tweet.first) || tweet.first == userId)
            {
                ans.push_back(tweet.second);
                count++;
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) 
    {
        users[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) 
    {
        users[followerId].erase(followeeId);
    }
};