class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < strs.size(); i++){
            string key = strs[i];
            sort(key.begin(), key.end());
            mp[key].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto& pair : mp){
            res.push_back(pair.second);
        }
        return res;
    }
};