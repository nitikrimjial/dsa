#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
// init at bottom
long long factorial[101] {1,1}, invFactorial[101] {1,1};
class Solution {
public:
    int countBalancedPermutations(const string& numStr) {
        int n = numStr.size();
        int freq[10] {};
        int targetSum = 0;
        for(char c : numStr) {
            freq[c-'0']++;
            targetSum += (c-'0');
        }
        // if sum of digits is odd, then it is impossible
        // to divide into 2 halfs with equal sum
        if(targetSum % 2 == 1) return 0;
        targetSum /= 2;
        
        int targetLen = n/2;
        // Number of ways to rearrange the 2 sub-arrays
        // ex: [1,2,3] -> [1,3,2] -> [2,1,3] -> [2,3,1]
        // If even length then it is (N/2)! * (N/2)!
        // If odd length then it is floor(N/2)! * ceil(N/2)!
        long long ways = (factorial[targetLen] * factorial[n-targetLen]) % MOD;

        vector dp(10, vector(targetLen + 1, vector(targetSum + 1, -1)));
        auto go = [&](this auto&& go, int i, int len1, int sum1) -> long long {
            if(i >= 10) {
                if(len1 == targetLen && sum1 == targetSum) return ways;
                return 0LL;
            }
            // len1,sum1 cannot decrease
            if(len1 > targetLen || sum1 > targetSum) {
                return 0LL;
            }
            if(dp[i][len1][sum1] >= 0) return dp[i][len1][sum1];
            long long ans = 0;
            for(int take = 0; take <= freq[i]; take++) {
                long long w = go(i + 1, len1 + take, sum1 + take * i);
// multiply by mod_inv is division in modulo M
// we're filtering out duplicates because:
// 2! = 2
// "11", "11" should be counted once (divide by 2!)
// "12", "21" should be counted twice (divide by 1!, divide by 1!)
// also needs to be done on subarr_1 and subarr_2
// which is why we divide by invFactorial take AND freq[i]-take
                w = (w * invFactorial[take]) % MOD;
                w = (w * invFactorial[freq[i]-take]) % MOD;
                ans = (ans + w) % MOD;
            }
            return dp[i][len1][sum1] = ans;
        };
        return go(0, 0, 0);
    }
};
long long mod_exp(long long base, long long exp) {
    base %= MOD;
    long long ans = 1;
    while(exp > 0) {
        if(exp & 1) {
            ans = (ans * base) % MOD;
        }
        exp >>= 1;
        base = (base * base) % MOD;
    }
    return ans;
}
auto init = [](){
    cin.tie(0)->sync_with_stdio(0);
    for(int i = 2; i <= 81; i++) {
        factorial[i] = (i * factorial[i - 1]) % MOD;
        invFactorial[i] = mod_exp(factorial[i], MOD-2);
    }
    return true;
}();