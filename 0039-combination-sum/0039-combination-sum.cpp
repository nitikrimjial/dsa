class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int i, int target, vector<int>& candidates) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (i == candidates.size() || target < 0) {
            return;
        }
        path.push_back(candidates[i]);
        dfs(i, target - candidates[i], candidates);  
        path.pop_back();
        dfs(i + 1, target, candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0, target, candidates);
        return ans;
    }
};