class Solution {
public:
    const int MOD = 1e9+7;
    unordered_map<string, int> memo;

    int numTilings(int n, bool previousGap = false) {
        if(n < 0) return 0;
        if(n == 0) return !previousGap;

        string key = to_string(n) + "_" + to_string(previousGap);
        if(memo.count(key)) return memo[key];

        if(previousGap)
            return memo[key] = (numTilings(n-1) + numTilings(n-1, true)) % MOD;

        return memo[key] = (numTilings(n-1) + numTilings(n-2) + 2LL*numTilings(n-2, true)) % MOD;
    }
};
