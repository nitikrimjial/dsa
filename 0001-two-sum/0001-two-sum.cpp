class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++){
            int cp = t - nums[i];
            if (map.find(cp) != map.end()){
                return {map[cp], i};
            }
             {
                map[nums[i]] = i;
            }
        }
        return {};
    }
};