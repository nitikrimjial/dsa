class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        int s = arr.size();
        
        for (int i = 0; i < s; i++) {
            if (arr[i] % 2 != 0) { 
                count++;
                if (count == 3) {
                    return true; 
                }
            } else {
                count = 0; 
            }
        }
        
        return false; 
    }
};