class Solution {
public:
    int totalMoney(int n) {
        int totalMoney = 0;
        int weekStart = 1;
        while(n > 0){
            int days = min(7, n);
            for(int i = 0; i < days; i++){
                totalMoney += weekStart + i;
            }
            weekStart++;
            n -= days;
        }
        return totalMoney;
    }
};