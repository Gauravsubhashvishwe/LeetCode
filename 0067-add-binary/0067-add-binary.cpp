class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.size();
        int j = b.size();
        i--;
        j--;
        bool cary = false;
        while(i >= 0 && j >= 0){
            bool l = (a[i] == '1')? true: false;
            bool m = (b[j] == '1')? true: false;
            if(cary & l & m ){
                result += '1';
            }
            else if((cary & l) | (cary & m) | (l & m)){
                result += '0';
                cary = true;
            }
            else if(cary | l | m){
                cary = false;
                result += '1';
            }
            else{
                result += '0';
            }
            i--;
            j--;
        }
        while(i >= 0){
            bool l = (a[i] == '1')? true: false;
            if(cary & l){
                result += '0';
            }
            else if(cary | l){
                result += '1';
                cary = false;
            }
            else{
                result += '0';
            }
            i--;
        }
        while(j >= 0){
            bool m = (b[j] == '1')? true: false;
            if(cary & m){
                result += '0';
            }
            else if(cary | m){
                result += '1';
                cary = false;
            }
            else{
                result += '0';
            }
            j--;
        }
        if(cary){
            result += '1';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};