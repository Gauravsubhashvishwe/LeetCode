class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<pair<int, int>> freq;
        for(int i = 0; i < 62; i++){
            freq.push_back({0, i});
        }
        for(int i = 0; i < n; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                freq[s[i] - 'a'].first++;
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                freq[s[i] - 'A' + 26].first++;
            }
            else{
                freq[s[i] - '0' + 52].first++;
            }
        }
        sort(freq.begin(), freq.end(), [](pair<int, int> &a, pair<int, int> &b){
            return a.first > b.first;
        });
        string result;
        for(int i = 0; i < 62; i++){
            int frq = freq[i].first;
            if(frq == 0)break;
            int char_id = freq[i].second;
            char ch;
            if(char_id < 26){
                ch = ('a' + char_id);
            }
            else if(char_id < 52){
                ch = ('A' + char_id - 26);
            }
            else{
                ch = ('0' + char_id - 52);
            }
            for(int j = 0; j < frq; j++){
                result += ch;
            }
        }
        return result;
    }
};