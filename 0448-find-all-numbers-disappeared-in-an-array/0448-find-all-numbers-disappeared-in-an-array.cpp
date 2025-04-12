class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans(nums.size() + 1, 0),res;
        
        for (int i = 0 ; i < nums.size(); i++){
            ans[nums[i]]++;
        }
        for (int i = 1; i < ans.size(); i++){
            if (ans[i]==0){
                res.push_back(i);
            }
        }
        return res;
    }
};