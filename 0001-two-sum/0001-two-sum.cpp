class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        vector<pair<int, int>> ans;
        for(int k = 0; k < nums.size(); k++){
            ans.push_back({nums[k], k});
        }
        sort(ans.begin(),ans.end());
        int i = 0, j = ans.size() - 1;
        while (i < j){
            int sum = ans[i].first + ans[j].first;
            if (sum == t){
                return {ans[i].second, ans[j].second};
            }
            else if (sum < t){
                i++;
            }
            else {
                j--;
            }
        }
        return {};
    }
};