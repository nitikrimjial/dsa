class Solution {
public:
    int coinChange(vector<int>& c, int a) {
        vector<int> dp(a + 1, INT_MAX - 1);
        dp[0] = 0;
        for(int i = 0; i < dp.size(); i++){
            for(int j = 0; j < c.size(); j++){
                if(i >= c[j]){
                    dp[i] = min(dp[i], 1 + dp[i - c[j]]);
                }
            }
        }
        if(dp[a] == INT_MAX - 1){
            return -1;
        }
        else{
            return dp[a];
        }
    }
};
