class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                t.push(s[i]);
            }
            else {
                if(t.empty()){
                    return false;
                }
                char top = t.top();
                if(s[i] == ')' && top != '(' || s[i] == '}' && top != '{' || s[i] == ']' && top != '[' ){
                    return false;
                }
                t.pop();
            }
        }
        return t.empty();
    }
};