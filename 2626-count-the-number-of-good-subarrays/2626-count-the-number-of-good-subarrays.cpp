class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> fre;
        long long ans = 0;
        long long paircount = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++){
            paircount += fre[nums[r]];
            fre[nums[r]]++;
            while (paircount >= k) {
                ans += (nums.size() - r);
                fre[nums[l]]--;
                paircount -= fre[nums[l]];
                l++;
            }
        }

        return ans;
    }
};
   