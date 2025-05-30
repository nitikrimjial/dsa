class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int pre = nums[0];
        int pre1 = 0;
        for(int i = 0; i < n; i++){
            int take = nums[i];
            if(i > 1) take += pre1;
            int nottake = 0 + pre;
            int cur = max(take, nottake);
            pre1 = pre;
            pre = cur;
        }
        return pre;
    }
};