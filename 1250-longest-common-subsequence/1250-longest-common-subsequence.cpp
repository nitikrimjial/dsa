class Solution {
public:
    int help(vector<vector<int>>& dp, int i, int j, string& s, string& t){
         if(i == s.size() || j == t.size()){
            return 0;
         }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == t[j]){
            return 1 + help(dp, 1 + i, 1 + j, s, t);
        }
        else{
            dp[i][j] = max( help(dp, i + 1, j, s, t), help(dp, i, j + 1, s, t));
        }
        return dp[i][j];

    }
    
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return help(dp, 0, 0, s, t);
        
    }
};