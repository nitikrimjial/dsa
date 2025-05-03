class Solution {
public:
    bool help(int i,vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        if( i == n - 1) return true;
        if(dp[i] != - 1) return dp[i];


        int maxreach = min(i + nums[i], n - 1);
        for(int j = i + 1; j <= maxreach; j++){
            if(help(j, nums, dp)){
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums){
        vector<int> dp(nums.size(), - 1);
        return help(0, nums, dp);
    }
};