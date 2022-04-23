class Solution {
public:
    string url;
    string tiny;
    
    Solution(){
        url = "";
        tiny = "";
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        url = longUrl;
        return "http://tinyurl.com/abcd";
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        tiny = shortUrl;
        return url;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));