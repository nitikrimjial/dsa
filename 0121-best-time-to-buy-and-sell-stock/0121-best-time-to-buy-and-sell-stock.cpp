class Solution {
public:
    int maxProfit(vector<int>& p) {
        int min_price= INT_MAX;
        int max_profit= 0;
        for(int i = 0; i < p.size(); i++){
          if(p[i] < min_price){
            min_price = p[i];
          }
          else if(p[i] - min_price > max_profit){
            max_profit = p[i] - min_price;
          }
        }
        return max_profit;
    }
};