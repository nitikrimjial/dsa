class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int maxDrink = numBottles;
        while(numBottles >= numExchange){
            int newBottles = numBottles / numExchange;
            int remainder = numBottles % numExchange;
            maxDrink += newBottles;
            numBottles = newBottles + remainder;
        }
        return maxDrink;
    }
}