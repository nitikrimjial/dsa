class Solution {
    public int maxProfit(int[] prices) {
        int minprice = prices[0];
        int maxprof = 0;
        for (int i = 0; i < prices.length; i++){
        if(minprice > prices[i]){
            minprice = prices[i];
        }
        int prof = prices[i] - minprice;
        maxprof = Math.max(prof,maxprof);
        }
        return maxprof;
    }
}