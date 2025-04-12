class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> flag(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++){
            flag[nums[i]]++;
        }
        for(int j = 0; j <= nums.size(); j++){
        if(flag[j] == 0){
            return j;
        }
        }
        return -1;
    }
};