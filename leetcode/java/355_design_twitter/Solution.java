import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.PriorityQueue;

public class Twitter {

    private static class Tweet implements Comparable<Tweet> {
        private final int time;
        private final int tweetId;

        private Tweet(int time, int tweetId) {
            this.time = time;
            this.tweetId = tweetId;
        }

        @Override
        public int compareTo(Tweet that) {
            int cmp = Integer.compare(that.time, this.time);
            if (cmp == 0) {
                cmp = Integer.compare(this.tweetId, that.tweetId);
            }
            return cmp;
        }
    }

    private static class News implements Comparable<News> {
        private final Tweet tweet;
        private final int authorId;
        private final int indexOfTweet;

        private News(Tweet tweet, int authorId, int indexOfTweet) {
            this.tweet = tweet;
            this.authorId = authorId;
            this.indexOfTweet = indexOfTweet;
        }

        @Override
        public int compareTo(News that) {
            int cmp = this.tweet.compareTo(that.tweet);
            if (cmp == 0) {
                cmp = Integer.compare(this.authorId, that.authorId);
            }
            if (cmp == 0) {
                cmp = Integer.compare(this.indexOfTweet, that.indexOfTweet);
            }
            return cmp;
        }
    }

    private final HashMap<Integer, HashSet<Integer>> following = new HashMap<>();
    private final HashMap<Integer, List<Tweet>> tweets = new HashMap<>();
    private int time = 0;

    /** Initialize your data structure here. */
    public Twitter() {

    }

    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        tweets.computeIfAbsent(userId, u -> new ArrayList<>())
                .add(new Tweet(time++, tweetId));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {
        PriorityQueue<News> pq = new PriorityQueue<>();
        List<Integer> output = new ArrayList<>();
        for (int id: following.computeIfAbsent(userId, u -> new HashSet<>())) {
            if (!tweets.containsKey(id) || tweets.get(id).isEmpty()) {
                continue;
            }
            List<Tweet> followingTweets = tweets.get(id);
            pq.add(new News(followingTweets.get(followingTweets.size()-1), id, followingTweets.size() - 1));
        }
        if (tweets.containsKey(userId)) {
            List<Tweet> userTweets = this.tweets.get(userId);
            if (!userTweets.isEmpty()) {
                pq.add(new News(userTweets.get(userTweets.size()-1), userId, userTweets.size() - 1));
            }
        }

        while (!pq.isEmpty() && output.size() < 10) {
            News top = pq.poll();
            output.add(top.tweet.tweetId);
            int id = top.authorId;
            if (top.indexOfTweet > 0) {
                List<Tweet> tweets = this.tweets.get(id);
                pq.add(new News(tweets.get(top.indexOfTweet - 1), id, top.indexOfTweet - 1));
            }
        }

        return output;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        following.computeIfAbsent(followerId, i -> new HashSet<>()).add(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
        following.computeIfAbsent(followerId, i -> new HashSet<>()).remove(followeeId);
    }

    public static void main(String[] args) {
        Twitter twitter = new Twitter();
        twitter.postTweet(1, 5);
        twitter.unfollow(1, 1);
        System.out.println(twitter.getNewsFeed(1));
    }
}
