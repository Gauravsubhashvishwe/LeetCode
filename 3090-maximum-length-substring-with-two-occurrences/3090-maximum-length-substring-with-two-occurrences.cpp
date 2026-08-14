class Solution {
public:
    int maximumLengthSubstring(string s) {
       int n = s.size();
       int freq[128] = {0};
       int j = 0;
       int result = 0;
       for(int i = 0; i < n; i++){
        freq[s[i]]++;
        while(freq[s[i]] > 2){
            freq[s[j]]--;
            j++;
        }
        result = max(result, i - j + 1);
       } 
       return result;
    }
};