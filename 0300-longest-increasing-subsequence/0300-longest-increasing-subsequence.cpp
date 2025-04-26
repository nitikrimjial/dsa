class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector(nums.size() + 1, -1));
         return help(nums, dp, 0, -1);
    }
    int help(vector<int>& nums,vector<vector<int>>& dp, int i, int pre){
        if(i == nums.size()){
            return 0;
        }
        if(dp[i][pre + 1] != -1){
            return dp[i][pre + 1];
        }
        int skip = help(nums, dp, i + 1, pre);
        int take = 0;
        if(pre == -1 || nums[i] > nums[pre]){
            take = 1 + help(nums, dp, i + 1, i);
        }
        dp[i][pre + 1] = max(take, skip);
        return dp[i][pre + 1];
    }
};