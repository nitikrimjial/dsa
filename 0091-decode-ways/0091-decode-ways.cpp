class Solution {
public:
    int help(int i, string& s, vector<int>& dp){
        if(i == s.length()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];

        int ways = help(i + 1, s, dp);
        if(i + 1 < s.length() && stoi(s.substr(i, 2)) <= 26){
            ways += help(i + 2, s, dp);
        }
        return dp[i] = ways;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, - 1);
        return help(0, s, dp);
    }
};