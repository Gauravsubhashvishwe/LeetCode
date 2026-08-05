class Solution {
    void helper(string op, int opn, int cl, vector<string> &result){
        if(opn == 0 && cl == 0){
            result.push_back(op);
        }
        else if(opn == cl){
            helper(op + '(', opn - 1, cl, result);
        }
        else if(opn == 0){
            helper(op + ')', opn, cl - 1, result);
        }
        else if(cl == 0){
            result.push_back(op);
            return;
        }
        else{
            helper(op + '(', opn - 1, cl, result);
            helper(op + ')', opn, cl - 1, result);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string op = "";
        helper(op, n, n, result);
        return result;
    }
};