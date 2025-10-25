// brute force 
// class Solution {
// public:
//     int totalMoney(int n) {
//         int totalMoney = 0;
//         int weekStart = 1;
//         while(n > 0){
//             int days = min(7, n);
//             for(int i = 0; i < days; i++){
//                 totalMoney += weekStart + i;
//             }
//             weekStart++;
//             n -= days;
//         }
//         return totalMoney;
//     }
// };
class Solution {
public:
    int totalMoney(int n) {
        int fullWeeks = n/7;
        int remainingDays = n % 7;

        int sum_fullWeeks = 28 * fullWeeks + 7 * (fullWeeks * (fullWeeks - 1))/2;
        int sum_remaining  = remainingDays * (fullWeeks + 1) + (remainingDays * (remainingDays - 1))/2;
        return sum_fullWeeks + sum_remaining;
    }
};