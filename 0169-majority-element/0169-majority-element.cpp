class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> fre;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            fre[nums[i]]++;
            if (fre[nums[i]] > n/2){
                return nums[i];
            }
        }
        return  -1;
    }
};