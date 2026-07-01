class Solution {
    vector<bool> visit;
    int n;

    void conn_comp(vector<vector<int>> &adjm, int p){
        visit[p] = true;
        stack<int> trav;
        trav.push(p);
        while(!trav.empty()){
            int top = trav.top();
            trav.pop();

            for(int i = 0; i < n; i++){
                if(adjm[top][i] == 1 && !visit[i]){
                    visit[i] = true;
                    trav.push(i);
                }
            }
        }
        return;
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        visit = vector<bool>(n, false);
        int comp = 0;
        for(int i = 0; i < n; i++){
            if(!visit[i]){
                conn_comp(isConnected, i);
                comp++;
            }
        }
        return comp;
    }
};