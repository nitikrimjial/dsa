class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum =( n*(n + 1))/2;
        int sim = 0;
        for (int i = 0; i < n; i++){
            sim = sim + nums[i];
        }
        return sum - sim;
        return -1;
    }
};