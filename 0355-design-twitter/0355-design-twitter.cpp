class Twitter {
public:
    unordered_map<int, unordered_set<int>> followerMap;
    unordered_map<int, vector<pair<int,int>>> tweetMap; // time, tweetId
    int time;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time, tweetId});
        time ++;
    }
    
    vector<int> getNewsFeed(int userId) {
        // for all followee, push in pq, maxHeap
        // {time, userId, index, tweetId}
        // pop 10 times
        auto& followees = followerMap[userId];
        priority_queue<vector<int>> pq;

        auto& ownTweets = tweetMap[userId];
        int lastIndex = ownTweets.size() - 1;
        if (lastIndex >= 0) {
            auto& lastTweet = ownTweets[lastIndex];
            auto lastTime = lastTweet.first;
            pq.push({lastTime, userId, lastIndex, lastTweet.second});
        }

        for (int f : followees) {
            auto& followeeTweets = tweetMap[f];
            int lastIndex = followeeTweets.size() - 1;
            if (lastIndex < 0) {
                continue;
            }

            auto& lastTweet = followeeTweets[lastIndex];
            auto lastTime = lastTweet.first;

            pq.push({lastTime, f, lastIndex, lastTweet.second});
        }

        int count = 10;
        vector<int> res;

        // cout << pq.size() << endl;
        while (!pq.empty() && count) {
            auto& newest = pq.top();
            int latestTime = newest[0];
            int followeeId = newest[1];
            int tweetIndex = newest[2];
            int tweetId = newest[3];
            pq.pop();

            res.push_back(tweetId);

            if (tweetIndex - 1 >= 0) {
                tweetIndex --;
                auto& followeeTweets = tweetMap[followeeId];
                auto& nextTweet = followeeTweets[tweetIndex];
                pq.push({nextTweet.first, followeeId, tweetIndex, nextTweet.second});
            }

            count --;
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followerMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followerMap[followerId].erase(followeeId);
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