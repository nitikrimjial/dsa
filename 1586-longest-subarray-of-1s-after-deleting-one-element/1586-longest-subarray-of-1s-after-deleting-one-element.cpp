class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = 1;
        int n = nums.size();
        int left = 0;
        int right;
        for (right = 0; right < n; right++){
            if (nums[right] == 0){
                k--;
            }
            if (k < 0 && nums[left++] == 0){
                k++;
            }
        }
        return right - left - 1;
    }
};