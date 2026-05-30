class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        int min = 0;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i + 1]) min = i + 1;
        }
        return nums[min];
    }
}