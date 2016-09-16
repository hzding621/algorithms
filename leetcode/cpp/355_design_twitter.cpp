#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(make_pair(time++, tweetId));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        
        using quadruple = tuple<int,int,int,int>; // time, value, id, index

        priority_queue<quadruple> pq;
        vector<int> output;
        for (int id: following[userId]) {
            if (tweets[id].size()) {
                pq.push(make_tuple(tweets[id].back().first, tweets[id].back().second, id, tweets[id].size()-1));
            }
        }
        if (tweets[userId].size()) {
            pq.push(make_tuple(tweets[userId].back().first, tweets[userId].back().second,
                               userId, tweets[userId].size()-1));
        }

        while (pq.size() && output.size() < 10) {
            auto best = pq.top();
            int time, value, id, index;
            tie(time, value, id, index) = best;
            pq.pop();
            output.push_back(value);
            if (index > 0) {
                pq.push(make_tuple(tweets[id][index-1].first, tweets[id][index-1].second, id, index-1));
            }
        }

        return output;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
private:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int,int>>> tweets;
    int time = 0;
};

int main() {

    Twitter twitter;

    twitter.postTweet(1, 5);

    auto vi = twitter.getNewsFeed(1);

    twitter.follow(1, 2);

    twitter.postTweet(2, 6);

    auto vi2 = twitter.getNewsFeed(1);

    twitter.unfollow(1, 2);

    auto vi3 = twitter.getNewsFeed(1);

    return 0;
}