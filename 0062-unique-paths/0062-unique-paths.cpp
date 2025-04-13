class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        return paths(dp,0,0);
    }
    int paths(vector<vector<int>> &dp , int i, int j){
        if(i >= size(dp) || j >= size(dp[0])) return 0;
        if(i == size(dp) - 1 && j == size(dp[0]) - 1) return 1;
        if(dp[i][j]) return dp[i][j];
        return dp[i][j] = paths(dp, i + 1, j) + paths(dp, i, j + 1);
    }
};