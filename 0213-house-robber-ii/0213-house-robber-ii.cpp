class Solution {
public:
    int help(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        vector<int> tem1, tem2;
        int n = nums.size();
        if(n == 1) return nums[0];
        for(int i = 0; i < n; i++){
            if(i != 0) tem1.push_back(nums[i]);
            if(i != n - 1) tem2.push_back(nums[i]);
        }
        return max(help(tem1), help(tem2));
    }
};