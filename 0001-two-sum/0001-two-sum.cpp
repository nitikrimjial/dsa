class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(t - nums[i] == nums[j]){
                    return {i,j};
                }
            }
        }
        return {};
    }
};