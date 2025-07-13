class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int k =players.size();
        int l =trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int res=0,p=0,q=0;
        while (p<k && q<l){
            if (players[p]<=trainers[q]){
                res++;
                p++;
                q++;
            }
            else q++;
        }
        return res;
    }
};