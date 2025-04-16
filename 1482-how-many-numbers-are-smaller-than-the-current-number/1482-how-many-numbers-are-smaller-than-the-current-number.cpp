class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> fre(101,0);
        for (int i : nums){
            fre[i]++;
        }
        for (int i = 1; i < 101; i++){
            fre[i] += fre[i - 1];
        }
        vector<int> res;
        for (int i : nums){
            if (i == 0){
                res.push_back(0);
            }
            else {
                res.push_back(fre[i - 1]);
            }
        }
        return res;
    }
};