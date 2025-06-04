class Solution {
public:
    string answerString(string word, int n) {
        if(n==1){return word;}
        
        string ans = "";
        int m = word.size();
        int mx_part_len = m - n + 1;

        for(int i=0;i<m;i++){
            string tmp = "";

            for(int j=i; j < min(i + mx_part_len , m);j++){

                tmp += word[j];

            }

            // cout<<tmp<<endl;
            if(tmp > ans){ ans = tmp;}
        }

        return ans;
    }
};