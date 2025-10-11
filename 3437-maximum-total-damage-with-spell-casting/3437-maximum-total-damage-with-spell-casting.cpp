class Solution {
public:
    unordered_map<int, int> mp;
    vector<long long> dp;
    vector<int> nextIndex;
    
    long long helper(int ind, int n, vector<int>& power) {
        if (ind >= n)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        
        long long maxi = 0;
        if (nextIndex[ind] < n)
            maxi = mp[power[ind]] * (long long)power[ind] + helper(nextIndex[ind], n, power);
        else
            maxi = mp[power[ind]] * (long long)power[ind];
        
        maxi = max(maxi, helper(ind + mp[power[ind]], n, power));
        return dp[ind] = maxi;
    }
    
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        for (auto it : power)
            mp[it]++;
        sort(power.begin(), power.end());

        // Precompute the next valid index for each index
        nextIndex.resize(n, n);  // Default to n (out of bounds)
        for (int i = 0; i < n; ++i) {
            int newInd = upper_bound(power.begin() + i + 1, power.end(), power[i] + 2) - power.begin();
            nextIndex[i] = newInd;
        }

        dp.resize(n, -1);
        return helper(0, n, power);
    }
};