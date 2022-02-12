class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    vector<pair<int,int>> tweets;
    
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
        following[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        int count = 0;
        vector<int> news;
        
        for(int i = tweets.size() -1; i >= 0; i --) {
            auto tweet = tweets[i];
            int tweetId = tweet.second;
            int poster = tweet.first;
            if(following[userId].count(poster) == 0)
                continue;
            
            news.push_back(tweetId);
            count ++;
            
            if(count == 10) {
                break;
            }
        }
        
        return news;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */