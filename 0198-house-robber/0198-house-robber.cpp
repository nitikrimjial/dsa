class Solution {
public:
    int help(int i, vector<int>& nums, vector<int>& dp){
        if(i == 0) return nums[i];
        if(i < 0)   return 0;

        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + help(i - 2, nums, dp);
        int notpick = 0 + help(i - 1, nums, dp);
        dp[i] = max(pick, notpick);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int i = nums.size();
        vector<int> dp(i, - 1);
        return help(i - 1, nums, dp);
    }
};