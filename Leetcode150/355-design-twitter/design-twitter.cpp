class Twitter {
private:
    int timestamp;
    struct Tweet{
        int time;
        int id;
    };
    unordered_map<int,unordered_set<int>> followers;
    unordered_map<int,vector<Tweet>> tweets;
public:
    Twitter() {
        timestamp=0;
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(timestamp++,tweetId);
        
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        followers[userId].insert(userId);
        for(int f: followers[userId]){
            auto& tlist = tweets[f];
            for(int i = max(0, (int)tlist.size()-10);i<tlist.size();i++){
                pq.push({tlist[i].time,tlist[i].id});
            }
        }
        vector<int> res;
        while(!pq.empty() && res.size()<10){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
        
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            followers[followerId].insert(followeeId);
        }
        
    }
    
    void unfollow(int followerId, int followeeId) {
         if(followerId != followeeId){
            followers[followerId].erase(followeeId);
        }
        
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