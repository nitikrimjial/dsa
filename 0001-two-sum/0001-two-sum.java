class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] copy = nums.clone();
        Arrays.sort(copy);
        int l = 0, r = copy.length - 1;
        while(l < r){
            int sum = copy[l] + copy[r];
            if(sum == target){
                int first = copy[l];
                int second = copy[r];
                int index1 = -1;
                int index2 = -1;
                for(int i = 0; i < nums.length; i++){
                    if(nums[i] == first && index1 == -1){
                        index1 = i;
                    }
                    else if(nums[i] == second && index2 == -1){
                        index2 = i;
                    }
                }
                return new int[] {index1, index2};
                
            }
            else if(sum > target){
                r--;
            }
            else {
                l++;
            }
        }
        return new int[]{};
    }
}