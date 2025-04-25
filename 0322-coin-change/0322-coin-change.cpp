class Solution {
public:
    int help(vector<int>& c, int a, int n, vector<vector<int>>& dp) {
        if(a == 0){
            return 0;
        }
        if (a < 0 || n < 0){
            return INT_MAX - 1;
        }
        if(dp[n][a] != -1){
            return dp[n][a];
        }
        int one = help(c, a, n - 1, dp);
        int two = 1 + help(c, a - c[n], n, dp);
        dp[n][a] = min(one, two);
        return dp[n][a];
    }
    int coinChange(vector<int>& c, int a){
        vector<vector<int>> dp(c.size() + 1, vector<int> (a + 1, -1));
        int ans = help(c, a, c.size() - 1, dp);
        if(ans == INT_MAX - 1){
            return -1;
        }
        else{
            return ans;
        }
    }
};