class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int n = g.size();
        int m = s.size();

        int j = n - 1;
        int result = 0;
        for(int i = m - 1; i >= 0; i--){
            while(j >= 0 && (g[j] > s[i]))j--;
            if(j >= 0)result++;
            else break;
            j--;
        }

        return result;
    }
};