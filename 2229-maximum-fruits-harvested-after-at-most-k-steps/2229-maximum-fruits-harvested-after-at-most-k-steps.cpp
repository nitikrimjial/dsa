class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fr, int sp, int k) {
        int n = 2e5 + 1;
        vector<int> v(n, 0);
        for(auto& x : fr) {
            v[x[0]] = x[1]; // store fruits at each position
        }
        
        long long ans = 0;        
        vector<long long> left(n, 0), right(n, 0); // prefix sum
        left[sp] = v[sp];
        right[sp] = v[sp];
        for(int i=sp-1; i>=0; i--) {
            left[i] = left[i+1] + v[i];
        }
        for(int i=sp+1; i<n; i++) {
            right[i] = right[i-1] + v[i];
        }
        
        for(int i=0; i<=min(k, sp); i++) { // move left 'i times' and 'i times' backwards
            int r = min(k-2*i, n-1-sp); // then, move right 'r times'
            if(r>=0 && sp+r<n) {
                ans = max(ans, left[sp-i] + right[sp+r] - v[sp]);
            }
        }
        
        for(int i=0; i<=min(k, n-1-sp); i++) { // move right 'i times' and 'i times' backwards
            int l = min(k-2*i, sp); // then, move left 'l times'
            if(l>=0 && sp-l>=0) {
                ans = max(ans, left[sp-l] + right[sp+i] - v[sp]);
            }
        }
        return (int)ans;
    }
};