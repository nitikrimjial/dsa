class Solution {
public:
    int MOD =1e9 + 7;
    int power(long long b, long long e){
        long long r = 1;
        while(e > 0){
            if(e % 2 == 1){
                r = (r * b) % MOD;
            }
            b = (b * b) % MOD;
            e /= 2;
        }
        return r;
    }
    int countGoodNumbers(long long n) {
        long long epos = (n + 1)/2;
        long long opos = n/2;
        long long eways = power(5, epos);
        long long oways = power(4, opos);
        return (eways * oways) % MOD;
    }
};