class Solution {
    public int numberOfBeams(String[] bank) {
        int beams = 0;
        int prev = 0;
        for(int i = 0; i < bank.length; i++){
            int count = 0;
            for(char c: bank[i].toCharArray()){
                if(c == '1') count++;
            }
        
        if(count > 0){
            beams += prev * count;
            prev = count;
        }
        }
        return beams;
    }
}