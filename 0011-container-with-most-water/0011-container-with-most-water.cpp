class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int water = 0;
        int max_water = 0;
        while(l < r){
            int h = min(height[l], height[r]);
            water = h * (r - l);
            while(height[l] <= h && l < r) {
                l++;
            }
            while (height[r] <= h && l < r){
                r--;
            }
            max_water = max(max_water, water);
        }
        return max_water;
    }
};
