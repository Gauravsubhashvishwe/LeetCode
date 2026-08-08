class Solution {
public:
    bool isValidSerialization(string preorder) {
       int n = preorder.size();
       int n_need = 1;
       for(int i = 0; i < n; i++){
        if(n_need <= 0)return false;
        if(preorder[i] == ',')continue;
        if(preorder[i] != '#'){
            n_need++;
        }
        else{
            n_need--;
        }
        while(i + 1 < n && preorder[i] >= '0' && preorder[i] <= '9')i++;
       }
       return n_need == 0;
    }
};