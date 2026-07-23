class Solution {
    string helper(string &s){
        string result = "";
        int count = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i - 1]){
                count++;
            }
            else{
                result += to_string(count) + s[i - 1];
                count = 1;
            }
        }
        result += to_string(count) + s.back();
        return result; 
    }
public:
    string countAndSay(int n) {
        string result = "1";
        for(int i = 1; i < n; i++){
            result = helper(result);
        }
        return result;
    }
};