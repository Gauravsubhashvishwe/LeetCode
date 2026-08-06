class Solution {
public:
    int smallestNumber(int n, int t) {
        vector<int> seen(10, 0);
        int cp = n;
        cp /= 100;
        while(cp > 0){
            seen[cp % 10]++;
            cp /= 10;
        }
        if(seen[0] > 0 || n % 10 == 0 || ((n / 10) % 10 == 0 && n / 10 != 0))return n;
        for(int i = 1; i < 10; i++){
            while(seen[i] > 0 && t > 1 && t % i == 0){
                t /= i;
                seen[i]--;
            }
        }
        if(t == 1)return n;
        while(1){
            int i = n % 10;
            int th = (n / 10) % 10;
            if(i % t == 0 || ((th % t == 0 || (i * th) % t == 0) && th != 0))return n;
            n++;
        }
    }
};