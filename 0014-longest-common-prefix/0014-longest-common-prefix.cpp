class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int i = 0;
        while(1){
            char ch = strs[0][i];
            for(int j = 0; j < n; j++){
                if(i < strs[j].size() && strs[j][i] == ch){
                    continue;
                }
                else{
                    return strs[0].substr(0, i);
                }
            }
            i++;
        }
        return "";
    }
};