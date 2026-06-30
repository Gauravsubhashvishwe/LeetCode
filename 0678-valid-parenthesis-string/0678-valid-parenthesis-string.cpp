class Solution {
public:
    bool checkValidString(string s) {
        int mino(0), maxo(0);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                maxo++;
                mino++;
            }
            else if(s[i] == ')'){
                mino--;
                maxo--;
            }
            else{
                mino--;
                maxo++;
            }

            if(maxo < 0)return false;
            mino = max(mino, 0);
        }
        return mino == 0;
    }
};