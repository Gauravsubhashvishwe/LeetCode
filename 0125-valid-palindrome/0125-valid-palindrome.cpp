class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int n = s.size();
        int i = 0;
        int j = n - 1;
        for(int i = 0; i < j; i++){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
                while(!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9')))j--;
                if(j < i)break;
                if(s[i] != s[j])return false;
                else{
                    j--;
                }
            }
        }
        return true;
    }
};