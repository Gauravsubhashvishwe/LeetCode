class Solution {

public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())return false;
        if(s == goal)return true;
        string cp = s + s;
        return cp.find(goal) != string::npos;
    }
};