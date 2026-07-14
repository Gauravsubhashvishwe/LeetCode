class Solution {
    bool satisfy(int sol,const vector<int> &piles, int h){
        int req_h = 0;
        for(int ban : piles){
            req_h += (ban + sol - 1) / sol;
        }
        return (req_h <= h);
    }
    int helper(int srt, int lst,const vector<int> &piles,const int &h){
        if(srt > lst)return -1;
        if(srt == lst)return srt;
        int mid = srt + (lst - srt)/2;
        if(satisfy(mid, piles, h)){
            return helper(srt, mid, piles, h);
        }
        else{
            return helper(mid + 1, lst, piles, h);
        }
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if(n > h)return -1;
        int mx = 0;
        for(int bnn : piles){
            mx = max(mx, bnn);
        }
        return helper(1, mx, piles, h);
    }
};