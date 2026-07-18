class Solution {
    string helper(int num, int mul){
        if(num == 0) return "";
        int front = num % 10;
        string result = helper(num / 10, mul * 10);
        
        if(mul == 1000){
            for(int i = 0; i < front; i++){
                result += 'M';
            }
            return result;
        }
        
        if(front == 9){
            if(mul == 100) result += "CM";
            if(mul == 10)  result += "XC";
            if(mul == 1)   result += "IX";
        }
        else if(front >= 5){
            if(mul == 100) { result += 'D'; for(int i = 0; i < front - 5; i++) result += 'C'; }
            if(mul == 10)  { result += 'L'; for(int i = 0; i < front - 5; i++) result += 'X'; }
            if(mul == 1)   { result += 'V'; for(int i = 0; i < front - 5; i++) result += 'I'; }
        }
        else if(front == 4){
            if(mul == 100) result += "CD";
            if(mul == 10)  result += "XL";
            if(mul == 1)   result += "IV";
        }
        else if(front >= 1){
            if(mul == 100) { for(int i = 0; i < front; i++) result += 'C'; }
            if(mul == 10)  { for(int i = 0; i < front; i++) result += 'X'; }
            if(mul == 1)   { for(int i = 0; i < front; i++) result += 'I'; }
        }
        
        return result;
}
public:
    string intToRoman(int num) {
        return helper(num, 1);
    }
};