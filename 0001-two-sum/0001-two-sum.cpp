class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); i++){
            int com = target - nums[i];
            if(umap.find(com) != umap.end()){
                return {umap[com], i};
            }
            umap[nums[i]] = i;
        }
        return {};
    }
};