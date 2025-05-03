class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pre(n, 1);
        for(int i = 1; i < m; i++){
            vector<int> cur(n, 0);
            for(int j = 0; j < n; j++){
                int up  = pre[j];
                int left = 0;
                if( j > 0){
                    left = cur[j - 1];
                }
                cur[j] = up + left;
            }
                pre = cur;
         }
         
          return pre[n - 1];
    }
};